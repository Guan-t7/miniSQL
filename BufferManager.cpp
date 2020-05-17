#include "BufferManager.h"
#include <fstream>

// 顺序读写 - 读取一个大文件
// use read() and write()
// mmap/CreateFileMapping is platform-specific

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
	pages.reserve(MAX_PAGES);
}

BufferManager::~BufferManager()
{
	flush();
	for (auto &&key_page : pages) delete[] key_page.second.m;
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
	void * m_ = alloc_space();
	ifstream fin(get<0>(p));
	fin.seekg(get<1>(p) * SIZEOF_PAGE);
	fin.read(static_cast<char*>(m_), SIZEOF_PAGE);
	return pages.emplace(p, Buf_Page(m_)).first->second;
}

void BufferManager::writeback_file(p_Page p)
{
	ofstream fout(get<0>(p));
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

void BufferManager::inform_deletion(string filename)
{
	for (auto &&key_page : pages)
	{
		if (get<0>(key_page.first) == filename)
		{
			key_page.second.pinned = key_page.second.dirty = key_page.second.clk_ref = false;
			// will be replaced physically when space is needed
		}
	}
}

void BufferManager::flush()
{
	for (auto &&key_page : pages)
	{
		if (key_page.second.dirty) writeback_file(key_page.first);
	}
}