#pragma once
#include "BufferManager.h"

using p_Entry = tuple<unsigned, unsigned>;	// pageNum, offs
// Ԥ��ʹ�� ch10 - Slotted Page Structure

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
	void select_record(string tableName, ...); //? ������ô���������ô����
	p_Entry insert_record(string tableName, ...); //? ��¼��ô��
	void delete_record(string tableName, ...);
};

