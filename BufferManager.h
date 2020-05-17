#pragma once
// UTF-8 
// C++11
#include <string>
#include <utility>	// tuple
#include <unordered_map>

using namespace std;

// buffer 由如下参数的 Pages 构成
const unsigned SIZEOF_PAGE = 4096;	//? make it bigger?
#ifdef DEBUG
const unsigned MAX_PAGES = 128;	// buffer: 512 K
#else
const unsigned MAX_PAGES = 128 * 1024;	// buffer: 512 M
#endif // DEBUG

/* 数据文件：预计每张表一个 relation.mdbf 
		大小超过 4G 时可能会有问题
	Advice: B+, one leaf node fits in one page. Index pageNum
*/
/* Responsibility: Buffer File I/O
	U manage structures stored in that page.
*/
using p_Page = tuple<string, unsigned>;	// filename, pageNum
struct Buf_Page;

class BufferManager
{
	unordered_map<p_Page, Buf_Page> pages;
	unsigned pinned_pages = 0;

	void * alloc_space();
	Buf_Page & read_file(p_Page p);
	void writeback_file(p_Page p);
public:
	BufferManager();
	~BufferManager();
	const void* getPage_r(p_Page p);
	void* getPage_w(p_Page p);
	int pinPage(p_Page p);	// 0 on success. may FAIL if u pin too many
	void unpinPage(p_Page p);
	void flush();	// write back all dirty pages to disk: sync the changes
};