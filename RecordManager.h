#pragma once
#include "BufferManager.h"

using p_Entry = tuple<unsigned, unsigned>;	// pageNum, offs
// 预计使用 ch10 - Slotted Page Structure

class RecordManager
{
private:
	BufferManager& bm;

public:
	RecordManager();
	~RecordManager();
	// 0 for success below
	int create_table(string tableName); 
	int drop_table(string tableName); //? whose duty to validate tableName
	void select_record(string tableName, ...); //? 条件怎么传，结果怎么返回
	p_Entry insert_record(string tableName, ...); //? 记录怎么传
	void delete_record(string tableName, ...);
};

