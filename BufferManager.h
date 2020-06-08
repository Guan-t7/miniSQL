#pragma once
// UTF-8 
// C++11
#include "pch.h" // tuple
#include <unordered_map>

using namespace std;
#define DEBUG

// buffer 由如下参数的 Pages 构成
const unsigned SIZEOF_PAGE = 4096;	//? make it bigger?
#ifdef DEBUG
const unsigned MAX_PAGES = 128;	// buffer: 512 K
#else
const unsigned MAX_PAGES = 128 * 1024;	// buffer: 512 M
#endif // DEBUG
// 用于存放 number of pages
const string BUF_META_PATH = "BUF_META";

/* Responsibility: Buffer File I/O
	U manage structures stored in that page.
 !	Physical file size doesn't reveal number of pages it really held.
*/
using p_Page = tuple<string, unsigned>;	// filename, pageNum
struct MyHash
{
	std::size_t operator()(p_Page const& p) const
	{
		std::size_t h1 = std::hash<std::string>{}(get<0>(p));
		std::size_t h2 = std::hash<unsigned>{}(get<1>(p));
		return h1 ^ (h2 << 1);
	}
};
struct Buf_Page;

class BufferManager // singleton
{
private:
	static BufferManager bm;
	unordered_map<p_Page, Buf_Page, MyHash> pages;
	unordered_map<string, unsigned> _totalPages;
	unsigned pinned_pages = 0;

	BufferManager();
	void operator=(BufferManager&); // disallowed
	void * alloc_space();
	Buf_Page & read_file(p_Page p);
	void writeback_file(p_Page p);
public:
	static BufferManager& instance() { return bm; }
	~BufferManager();
	const void* getPage_r(p_Page p);
	void* getPage_w(p_Page p);
	void set_dirty(p_Page p);
	unsigned totalPages(string filename);
	// int: 0 on success below
	int pinPage(p_Page p);	// may FAIL if u pin too many
	void unpinPage(p_Page p);
	int create_file(string filename);
	int delete_file(string filename);
	void flush();	// write back all dirty pages to disk: sync the changes
};

#undef DEBUG