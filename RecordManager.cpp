#include "RecordManager.h"
#include "pch.h"

using namespace std;

RecordManager::RecordManager() : bm(BufferManager::instance())
{
	
}


RecordManager::~RecordManager()
{
}

int RecordManager::create_table(string tableName)
{
	ofstream fo(tableName + ".mdbf");
	return fo.fail();
}

int RecordManager::drop_table(string tableName)
{
	int r = remove((tableName + ".mdbf").c_str());
	bm.inform_deletion(tableName + ".mdbf");
	return r;
}

struct Entry
{
	unsigned offs_start;
	unsigned size;
};
struct Sl_Pg_Head
{
	unsigned n_entries;
	unsigned end_fspace;
	Entry en;
};

void RecordManager::select_record(string tableName, ...)
{
	// sel all below
	int n_pages; //todo get from Catalog
	for (size_t i = 0; i < n_pages; i++)
	{
		const void* p_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", i));
		const Sl_Pg_Head* p_slPage = static_cast<const Sl_Pg_Head*> (p_pg);
		const Entry* _p_entry = &p_slPage->en;
		for (size_t i = 0; i < p_slPage->n_entries; i++)
		{
			const void *p_record = static_cast<const void*>(static_cast<const char*> (p_pg) + _p_entry->offs_start);	//todo return?
			_p_entry++;
		}
	}
}
//? UNTESTED