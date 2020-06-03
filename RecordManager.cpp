#include "RecordManager.h"
#include "pch.h"

//todo 内存管理
RecordManager::RecordManager() : bm(BufferManager::instance())
{
}

RecordManager::~RecordManager()
{
}

int RecordManager::create_table(string tableName)
{
	return bm.create_file(tableName + ".mdbf");
}

int RecordManager::drop_table(string tableName)
{
	return bm.delete_file(tableName + ".mdbf");
}

struct Entry
{
	unsigned offs_start;
	unsigned short size;
	bool valid;
	//todo null bitmap
};
struct Sl_Pg_Head
{
	unsigned n_entries;
	unsigned end_fspace; // 页内的free space是[第n_entries项 Entry, end_fspace)
	Entry en;
};

// access and manip the storage; do comp in certain field
// full table scan
// 从……获得table的模式信息：比如一条记录各field的类型和大小
// 对table中的每个Page，对Page中的每条record 进行parse
// 从……得到查询条件
vector<vector<string>> RecordManager::select(string tableName, vector<Condition> conds) //todo 如何运用索引
{
	int n_pages = bm.totalPages(tableName + ".mdbf");
	vector<vector<string>> res;
	for (size_t i = 0; i < n_pages; i++) // trav each page
	{
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", i)); // ptr pointing to mem loc
		const Sl_Pg_Head* mp_slPage = static_cast<const Sl_Pg_Head*> (mp_pg);
		const Entry* mp_entry = &mp_slPage->en;
		for (size_t i = 0; i < mp_slPage->n_entries; i++, mp_entry++) // get one record
		{
			if (!mp_entry->valid) continue;
			const void *mp_record = static_cast<const char*> (mp_pg) + mp_entry->offs_start;

			vector<string> vs_record;
			bool fit = true;
			for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size() && fit; i++) // get each field
			{
				auto &&col = cm.getTableInfo(tableName).metadata[i];
				pair<DataType, int> type = eType(col.type);
				_DataType *data = mk_obj(type, mp_record);
				vs_record.push_back(data->to_string());
				// check conds
				for (auto&& c : conds)
				{
					if (c.col == col.name)
					{
						_DataType* cond_val = mk_obj(type, c.val);
						fit = cond_fit(c, data, cond_val);
						if (!fit) break;
					}
				}
				mp_record = (const char*)mp_record + data->size(); // step to next field
			}
			if (fit) res.push_back(vs_record);
		}
	}
}
int RecordManager::insert(string tableName, std::vector<std::string> s_vals)
{
	// access
	unsigned n_pages = bm.totalPages(tableName + ".mdbf");
	// unique integrity check
	vector<Condition> conds;
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
	{
		auto &&col = cm.getTableInfo(tableName).metadata[i];
		if (col.unique)
		{
			conds.emplace_back(Condition(col.name, E, s_vals[i]));
		}
	}
	if (!select(tableName, conds).empty()) return 1;
	// Field对象构造出来，同时确定记录长度
	unsigned rec_size = 0;
	_DataType** dataArr = new _DataType*[cm.getTableInfo(tableName).metadata.size()];
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
	{
		auto &&col = cm.getTableInfo(tableName).metadata[i];
		pair<DataType, int> type = eType(col.type);
		dataArr[i] = mk_obj(type, s_vals[i]);
		rec_size += dataArr[i]->size();
	}
	// trav each page
	for (size_t i = 0; i < n_pages; i++) 
	{
		// 确认该页有没有足够的空当
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", i)); // ptr pointing to mem loc
		const Sl_Pg_Head* mp_slPage = static_cast<const Sl_Pg_Head*> (mp_pg);
		const Entry* mp_entry = &mp_slPage->en;
		
		unsigned space_left = mp_slPage->end_fspace - ((const char*)(mp_entry + mp_slPage->n_entries) - (const char*)mp_pg);
		if (space_left > rec_size + sizeof(Entry)) // begin w
		{
			insert_page(tableName, i, rec_size, dataArr);
		}
	}
	// get a new page
	void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", n_pages));
	// init
	Sl_Pg_Head* mp_slPage = static_cast<Sl_Pg_Head*> (mp_pg);
	mp_slPage->n_entries = 0;
	mp_slPage->end_fspace = SIZEOF_PAGE;
	// insert to this page
	insert_page(tableName, n_pages, rec_size, dataArr);
	
	return 0;
}

void RecordManager::insert_page(std::string &tableName, size_t i, unsigned int rec_size, _DataType * dataArr[])
{
	void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", i));
	Sl_Pg_Head* mp_slPage = static_cast<Sl_Pg_Head*> (mp_pg);
	mp_slPage->n_entries++;
	mp_slPage->end_fspace -= rec_size;

	Entry* mp_entry = &mp_slPage->en;
	mp_entry[mp_slPage->n_entries].offs_start = mp_slPage->end_fspace;
	mp_entry[mp_slPage->n_entries].size = rec_size;
	mp_entry[mp_slPage->n_entries].valid = true;

	char* mp_record = (char*)mp_pg + mp_entry[mp_slPage->n_entries].offs_start;
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
	{
		dataArr[i]->dump(mp_record);
		mp_record += dataArr[i]->size();
	}
}

int RecordManager::delete_rec(string tableName, vector<Condition> conds)
{
	int count = 0;
	// access
	int n_pages = bm.totalPages(tableName + ".mdbf");
	for (size_t i = 0; i < n_pages; i++) // trav each page
	{
		void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", i)); // ptr pointing to mem loc
		//todo refactor for extraction 先读，确认后再申请写
		Sl_Pg_Head* mp_slPage = static_cast<Sl_Pg_Head*> (mp_pg);
		Entry* mp_entry = &mp_slPage->en;
		for (size_t i = 0; i < mp_slPage->n_entries; i++, mp_entry++) // get one record
		{
			if (!mp_entry->valid) continue; //? n_entries inconsistency
			const void *mp_record = static_cast<const char*> (mp_pg) + mp_entry->offs_start;

			bool fit = true;
			for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size() && fit; i++) // get each field
			{
				auto &&col = cm.getTableInfo(tableName).metadata[i];
				pair<DataType, int> type = eType(col.type);
				_DataType *data = mk_obj(type, mp_record);
				// check conds
				for (auto&& c : conds)
				{
					if (c.col == col.name)
					{
						_DataType* cond_val = mk_obj(type, c.val);
						fit = cond_fit(c, data, cond_val);
						if (!fit) break;
					}
				}
				mp_record = (const char*)mp_record + data->size(); // step to next field
			}
			if (fit)
			{
				mp_entry->valid = false; //todo real deletion
				count++;
			}
		}
	}
	return count;
}

bool RecordManager::cond_fit(Condition & c, _DataType *data, _DataType * cond_val)
{
	bool fit = true;
	switch (c.op)
	{
	case E:
		if (!(*data == *cond_val)) fit = false;
		break;
	case NE:
		if (*data == *cond_val) fit = false;
		break;
	case L:
		if (!(*data < *cond_val)) fit = false;
		break;
	case GE:
		if (*data < *cond_val) fit = false;
		break;
	case G:
		if (*data < *cond_val || *data == *cond_val) fit = false;
		break;
	case LE:
		if (!(*data < *cond_val || *data == *cond_val)) fit = false;
		break;
	default:
		break;
	}
	return fit;
}
_DataType* RecordManager::mk_obj(std::pair<DataType, int> &type, const void * mp_record)
{
	switch (type.first)
	{
	case IntType:
		return new T_Type<int>(mp_record);
		break;
	case FloatType:
		return new T_Type<double>(mp_record);
		break;
	case StringType:
		return new _StringType(mp_record, type.second);
		break;
	default:
		return nullptr;
		break;
	}
}
_DataType* RecordManager::mk_obj(std::pair<DataType, int>& type, const string & val)
{
	switch (type.first)
	{
	case IntType:
		return new T_Type<int>(stoi(val));
		break;
	case FloatType:
		return new T_Type<double>(stoi(val));
		break;
	case StringType:
		return new _StringType(val);
		break;
	default:
		return nullptr;
		break;
	}
}
//? UNTESTED