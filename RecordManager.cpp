#include "RecordManager.h"
#include "pch.h"
const unsigned FILL = 0x100; // 摊还由懒惰删除引起的插入代价
static unsigned F = 0;

//todo index；
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
	unsigned offs2start; // relative to the start of page
	unsigned short size;
	bool valid;
	//todo null bitmap
};
struct Sl_Pg_Head
{
	unsigned n_entries;
	unsigned end_fspace; // 页内的free space是[第n_entries项 Entry, end_fspace)
	Entry ent;
	void init() { n_entries = 0; end_fspace = SIZEOF_PAGE; }
};

// access and manip the storage; do comp in certain field
// 从……获得table的模式信息：比如一条记录各field的类型和大小
// 对table中的每个Page，对Page中的每条record 进行parse
// 从……得到查询条件
vector<vector<string>> RecordManager::select(const string & tableName, const vector<Condition>& conds, const vector<p_Entry>& candidates)
{
	if (candidates.empty()) return to_print(tableName, full_table_scan(tableName, conds));
	else return to_print(tableName, range_scan(tableName, conds, candidates));
}

int RecordManager::insert(string tableName, std::vector<std::string> s_vals) //todo I'm still not satisfied
{
	// access
	unsigned n_pages = bm.totalPages(tableName + ".mdbf");
	// unique integrity check
	vector<Condition> conds;
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
	{
		auto col = cm.getTableInfo(tableName).metadata[i]; //! bug: returning temp obj, cannot use reference
		if (col.unique)
		{
			conds.emplace_back(Condition(col.name, opType::E, s_vals[i]));
		}
	}
	if (!select(tableName, conds).empty()) return 1; //todo 调api
	// Field对象构造出来，同时确定记录长度
	unsigned rec_size = 0;
	_DataType** dataArr = new _DataType*[cm.getTableInfo(tableName).metadata.size()];
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
	{
		auto col = cm.getTableInfo(tableName).metadata[i];
		pair<DataType, int> type = eType(col.type);
		dataArr[i] = mk_obj(type, s_vals[i]);
		rec_size += dataArr[i]->size();
	}
	// an opt based on probability （效果一般，耗时随记录数上升显著 e.g. 1000 rec - 0.2 s/insert
	if (F == FILL) 
	{
		for (size_t pageNum = 0; pageNum < n_pages; pageNum++) // trav each page
		{
			const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", pageNum)); // ptr pointing to mem loc
			const Sl_Pg_Head* mp_slPage = reinterpret_cast<const Sl_Pg_Head*> (mp_pg);
			const Entry* mp_entry = &mp_slPage->ent;
			// 看该页可有被懒惰删除的项
			for (size_t i = 0; i < mp_slPage->n_entries; i++, mp_entry++) // trav each record in the page
			{
				if (!mp_entry->valid && mp_entry->size > rec_size) // 被懒惰删除的项 可用
				{
					bm.set_dirty(make_tuple(tableName + ".mdbf", pageNum));
					const_cast<Entry*>(mp_entry)->size = rec_size;
					const_cast<Entry*>(mp_entry)->valid = true;
					dump_rec((char*)mp_pg + mp_entry->offs2start, dataArr, cm.getTableInfo(tableName).metadata.size());
					// todo inform index 
					return 0;
				}
			}
		}
		F = 0;
	}
	F++;
	// 径直去最后一页看有没有足够的空当
	if (n_pages) //! 边界条件
	{
		size_t pageNum = n_pages - 1;
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", pageNum)); 
		const Sl_Pg_Head* mp_slPage = reinterpret_cast<const Sl_Pg_Head*> (mp_pg);
		const Entry* mp_entry = &mp_slPage->ent;

		unsigned space_left = mp_slPage->end_fspace - ((char*)(mp_entry + mp_slPage->n_entries) - (char*)mp_pg);
		if (space_left > rec_size + sizeof(Entry)) // 有足够的空当, new entry
		{
			insert2newEntry(tableName, pageNum, rec_size, dataArr);
			return 0; //! bug: return after d
		}
	}
	// 已有的页都无法插入，get a new page and init
	void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", n_pages));
	Sl_Pg_Head* mp_slPage = reinterpret_cast<Sl_Pg_Head*> (mp_pg);
	mp_slPage->init();
	// insert to this page
	insert2newEntry(tableName, n_pages, rec_size, dataArr);

	return 0;
}


void RecordManager::dump_rec(char * mp_record, const _DataType * const dataArr[], unsigned n)
{
	for (size_t i = 0; i < n; i++)
	{
		dataArr[i]->dump(mp_record);
		mp_record += dataArr[i]->size();
	}
}

void RecordManager::insert2newEntry(const string & tableName, size_t i, unsigned int rec_size, const _DataType * const dataArr[])
{
	void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", i));
	Sl_Pg_Head* mp_slPage = reinterpret_cast<Sl_Pg_Head*> (mp_pg);
	mp_slPage->end_fspace -= rec_size;

	Entry* mp_entry = &mp_slPage->ent;
	mp_entry += mp_slPage->n_entries; // to TGT
	mp_entry->offs2start = mp_slPage->end_fspace;
	mp_entry->size = rec_size;
	mp_entry->valid = true;

	char* mp_record = (char*)mp_pg + mp_entry->offs2start;
	dump_rec(mp_record, dataArr, cm.getTableInfo(tableName).metadata.size());
	mp_slPage->n_entries++;
	//todo inform index
	//! free space here
	kill_obj(tableName, dataArr);
}

void RecordManager::kill_obj(const std::string & tableName, const _DataType *const * dataArr)
{
	for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++)
		delete dataArr[i];
	delete[] dataArr;
}

vector<p_Entry> RecordManager::range_scan(const string & tableName, const vector<Condition>& conds, const vector<p_Entry>& candidates)
{
	vector<p_Entry> res;
	for (auto&& candidate : candidates)
	{
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", get<0>(candidate)));
		const Entry* mp_entry = reinterpret_cast<const Entry*>((const char*)mp_pg + get<1>(candidate));
		const void *mp_record = (const char*)mp_pg + mp_entry->offs2start;
		bool fit = conds_fit(cm.getTableInfo(tableName).metadata, mp_record, conds);
		if (fit) res.push_back(candidate);
	}
	return res;
}
vector<p_Entry> RecordManager::full_table_scan(const string & tableName, const vector<Condition>& conds)
{
	vector<p_Entry> res;
	for (size_t pageNum = 0; pageNum < bm.totalPages(tableName + ".mdbf"); pageNum++) // trav each page
	{
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", pageNum)); // mp: ptr pointing to mem loc
		const Sl_Pg_Head* mp_slPage = reinterpret_cast<const Sl_Pg_Head*> (mp_pg);
		const Entry* mp_entry = &mp_slPage->ent;
		for (size_t i = 0; i < mp_slPage->n_entries; i++, mp_entry++) // trav each record in the page
		{
			if (!mp_entry->valid) continue; //! bug: It's NOT a break condition
			const void *mp_record = (const char*)mp_pg + mp_entry->offs2start; // ptr to the start of this record
			bool fit = conds_fit(cm.getTableInfo(tableName).metadata, mp_record, conds);
			if (fit) res.push_back(p_Entry{ pageNum,(const char*)mp_entry - (const char*)mp_pg });
		}
	}
	return res;
}

vector<vector<string>> RecordManager::to_print(const string & tableName, const vector<p_Entry>& list)
{
	vector<vector<string>> res;
	for (auto&& ent : list)
	{
		const void* mp_pg = bm.getPage_r(make_tuple(tableName + ".mdbf", get<0>(ent)));
		const Entry* mp_entry = reinterpret_cast<const Entry*>((const char*)mp_pg + get<1>(ent));
		const void *mp_record = (const char*)mp_pg + mp_entry->offs2start;
		vector<string> vs_record;
		for (size_t i = 0; i < cm.getTableInfo(tableName).metadata.size(); i++) // get each field
		{
			auto col = cm.getTableInfo(tableName).metadata[i];
			pair<DataType, int> type = eType(col.type);
			_DataType *data = mk_obj(type, mp_record);
			vs_record.push_back(data->to_string());
			mp_record = (const char*)mp_record + data->size(); // step to next field
			delete data;
		}
		res.push_back(vs_record);
	}
	return res;
}

void RecordManager::set_invalid(const string & tableName, const vector<p_Entry>& list)
{
	for (auto&& ent : list)
	{
		void* mp_pg = bm.getPage_w(make_tuple(tableName + ".mdbf", get<0>(ent)));
		Entry* mp_entry = reinterpret_cast<Entry*>((char*)mp_pg + get<1>(ent));
		mp_entry->valid = false;
	}
}
int RecordManager::delete_rec(string tableName, vector<Condition> conds, const vector<p_Entry>& candidates)
{
	vector<p_Entry> list;
	if (candidates.empty())
		list = move(full_table_scan(tableName, conds));
	else
		list = move(range_scan(tableName, conds, candidates));
	set_invalid(tableName, list);
	return list.size();
}

pair<DataType, int> eType(pair<std::string, int> type)
{
	if (type.first == "int") return make_pair(IntType, 0);
	else if (type.first == "float") return make_pair(FloatType, 0);
	else return make_pair(StringType, type.second);
}

bool RecordManager::conds_fit(const vector<Column> colMetas, const void * mp_record, const std::vector<Condition> & conds)
{
	bool fit = true;
	for (size_t i = 0; i < colMetas.size() && fit; i++) // get each field
	{
		auto &&colMeta = colMetas[i];
		pair<DataType, int> type = eType(colMeta.type);
		_DataType* data = mk_obj(type, mp_record); // construct data from void*
		for (auto&& cond : conds) // check conds
		{
			if (cond.col == colMeta.name)
			{
				_DataType* cond_val = mk_obj(type, cond.val);
				fit = cond_fit(cond, data, cond_val);
				delete cond_val;
				if (!fit) break;
			}
		}
		mp_record = (const char*)mp_record + data->size(); // step to next field
		delete data;
	}
	return fit;
}
bool RecordManager::cond_fit(const Condition & c, const _DataType *data, const _DataType * cond_val)
{
	bool fit = true;
	switch (c.op)
	{
	case opType::E:
		if (!(*data == *cond_val)) fit = false;
		break;
	case opType::NE:
		if (*data == *cond_val) fit = false;
		break;
	case opType::L:
		if (!(*data < *cond_val)) fit = false;
		break;
	case opType::GE:
		if (*data < *cond_val) fit = false;
		break;
	case opType::G:
		if (*data < *cond_val || *data == *cond_val) fit = false;
		break;
	case opType::LE:
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
		return new T_Type<double>(stod(val));
		break;
	case StringType:
		return new _StringType(val, type.second);
		break;
	default:
		return nullptr;
		break;
	}
}