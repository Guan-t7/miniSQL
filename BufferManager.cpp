#include "BufferManager.h"
#include "pch.h"

// 顺序读写 - 读取一个大文件
// use read() and write()
// mmap/CreateFileMapping is platform-specific

BufferManager BufferManager::bm;

struct Buf_Page
{
	bool dirty;
	bool pinned;
	bool clk_ref;
	void* m;
	Buf_Page(void* m_ = nullptr) :dirty(false), pinned(false), clk_ref(true), m(m_) {}
};

BufferManager::BufferManager()
{
	ifstream fi(BUF_META_PATH); // load meta from disk
	if (!fi.fail())
	{
		string filename;
		unsigned count;
		while (fi.peek() != EOF)
		{
			(fi >> filename >> count).get();
			_totalPages[filename] = count;
		}
	}
	pages.reserve(MAX_PAGES);
}

BufferManager::~BufferManager()
{
	flush();
	for (auto &&key_page : pages) delete[] key_page.second.m;
	ofstream fo(BUF_META_PATH); // save meta to disk
	for (auto&& i : _totalPages)
	{
		fo << i.first << " " << i.second << endl;
	}
}

void * BufferManager::alloc_space()
{
	if (pages.size() == MAX_PAGES) // buffer is full. clock approx.
	{
		while (true)
		{
			for (auto &&key_page : pages)
			{
				if (key_page.second.pinned) continue;
				else if (key_page.second.clk_ref) key_page.second.clk_ref = false;
				else // choose this page for replacement
				{
					if (key_page.second.dirty) writeback_file(key_page.first);
					void * m_ = key_page.second.m;
					pages.erase(key_page.first);	//! iterator invalidated. OK here.
					return m_;
				}
			}
		}
	}
	return new char[SIZEOF_PAGE];
}

Buf_Page & BufferManager::read_file(p_Page p)
{
	string &filename = get<0>(p);
	unsigned pageNum = get<1>(p);
	// test file size. inflate the file if needed.
	fstream fin(filename, ios::binary | ios::in | ios::out | ios::ate); //! bug: missing bit masks 
	if (fin.tellg() / SIZEOF_PAGE < (pageNum + 1))
	{
		fin.seekp(2 * (pageNum + 1)*SIZEOF_PAGE - 1);
		fin.write("", 1);
	}
	// update totalPages stat 
	_totalPages[filename] = max(_totalPages[filename], pageNum + 1);
	// read from disk to mem
	void * m_ = alloc_space();
	fin.seekg(pageNum * SIZEOF_PAGE);
	fin.read(static_cast<char*>(m_), SIZEOF_PAGE);
	return pages.emplace(p, Buf_Page(m_)).first->second;
}

void BufferManager::writeback_file(p_Page p)
{
	ofstream fout(get<0>(p), ios::binary | ios::in | ios::out); //! bug: missing bit masks
	fout.seekp(get<1>(p) * SIZEOF_PAGE);
	fout.write(static_cast<char*>(pages[p].m), SIZEOF_PAGE);
	pages[p].dirty = false;
}

const void * BufferManager::getPage_r(p_Page p)
{
	if (!pages.count(p)) read_file(p);
	pages[p].clk_ref = true;
	return pages[p].m;
}

void * BufferManager::getPage_w(p_Page p)
{
	if (!pages.count(p)) read_file(p);
	pages[p].clk_ref = true;
	pages[p].dirty = true;
	return pages[p].m;
}

unsigned BufferManager::totalPages(string filename)
{
	if (_totalPages.count(filename))
		return _totalPages[filename];
	return 0;
}

int BufferManager::pinPage(p_Page p)
{
	if (pinned_pages * 2 > MAX_PAGES) return 1;
	if (!pages.count(p)) read_file(p);
	if (!pages[p].pinned)
	{
		pages[p].pinned = true;
		pinned_pages++;
	}
	return 0;
}

void BufferManager::unpinPage(p_Page p)
{
	if (pages.count(p) && pages[p].pinned)
	{
		pages[p].pinned = false;
		pinned_pages--;
	}
}

int BufferManager::create_file(string filename)
{
	_totalPages[filename] = 0;
	ofstream fo(filename);
	return fo.fail();
}

int BufferManager::delete_file(string filename)
{
	for (auto &&key_page : pages)
	{
		if (get<0>(key_page.first) == filename)
		{
			key_page.second.pinned = key_page.second.dirty = key_page.second.clk_ref = false;
			// will be replaced physically when space is needed
		}
	}
	_totalPages.erase(filename);
	return remove(filename.c_str());
}

void BufferManager::flush()
{
	for (auto &&key_page : pages)
	{
		if (key_page.second.dirty) writeback_file(key_page.first);
	}
}