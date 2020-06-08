#pragma once
#include "BufferManager.h"
//#include "IndexManager.h"
#include "SimpleSQLInterpreter/DBInfo.h"
#include "SimpleSQLInterpreter/CatalogManager.h"
#include "SimpleSQLInterpreter/SelectResult.h"

using p_Entry = tuple<unsigned, unsigned>;	// pageNum, offs
// 预计使用 ch10 - Slotted Page Structure

// Items within a single record 口区
// continuous storage; 同一种数据类型 comparable; has a size(probably variable)
class _DataType
{
public:
	virtual ~_DataType() {}
	virtual size_t size() const = 0;
	virtual bool operator<(const _DataType &d2) const = 0;
	virtual bool operator==(const _DataType &d2) const = 0;
	virtual string to_string() const = 0;
	virtual void dump(char* p) const = 0; // 序列化到page上
};
// emmm要做的其实是 根据提示进行序列化和反序列化

class RecordManager
{
private:
	BufferManager& bm;
	CatalogManager cm;
	/*IndexManager im;*/

	_DataType * mk_obj(std::pair<DataType, int>& type, const void * mp_record);
	_DataType * mk_obj(std::pair<DataType, int>& type, const string& val);
	bool conds_fit(const vector<Column> colMetas, const void * mp_record, const std::vector<Condition>& conds);
	bool cond_fit(const Condition & c, const _DataType *data, const _DataType * cond_val);
	void dump_rec(char* mp_record, const _DataType * const dataArr[], unsigned n);
	void insert2newEntry(const string & tableName, size_t i, unsigned int rec_size, const _DataType * const dataArr[]);
	void kill_obj(const std::string & tableName, const _DataType *const * dataArr);
	vector<p_Entry> range_scan(const string &tableName, const vector<Condition> &conds, const vector<p_Entry> &candidates);
	vector<p_Entry> full_table_scan(const string & tableName, const vector<Condition>& conds);
	vector<vector<string>> to_print(const string &tableName, const vector<p_Entry> &list);
	void set_invalid(const string &tableName, const vector<p_Entry> &list);

public:
	RecordManager();
	~RecordManager();
	int create_table(string tableName); // 0 for success
	int drop_table(string tableName); // 0 for success
	// no candidates: full table scan; otherwise index range scan
	vector<vector<string>> select(const string &tableName, const vector<Condition> &conds, const vector<p_Entry> &candidates = vector<p_Entry>{});
	int insert(string tableName, std::vector<std::string> s_vals); 	// 0 for success
	//todo I have p_Entry for index insert
	int delete_rec(string tableName, vector<Condition> conds, const vector<p_Entry> &candidates = vector<p_Entry>{}); //! this one returns count of records deleted
	//todo index del
};


template<typename T> // int, double
class T_Type : public _DataType
{
	T d;
public:
	T_Type(const T val) : d(val) {}
	T_Type(const void* p) { d = *(T*)p; }
	size_t size() const { return sizeof(T); }
	bool operator<(const _DataType &d2) const { return d < dynamic_cast<const T_Type &>(d2).d; }
	bool operator==(const _DataType &d2) const { return d == dynamic_cast<const T_Type &>(d2).d; }
	string to_string() const { return std::to_string(d); }
	void dump(char* p) const { *(T*)p = d; }
};
class _StringType : public _DataType //todo be modified to adapt varchar
{
	string d;
	size_t m_size;
public:
	_StringType(string val, size_t size) :d(val), m_size(size) { d.resize(size, '\0'); } //! bug: fixed len char(n), m_size should be that in Catalog
	_StringType(const void* p, size_t size) :d((char*)p, (char*)p + size), m_size(size) {}
	size_t size() const { return m_size; }
	bool operator<(const _DataType &d2) const { return d < dynamic_cast<const _StringType &>(d2).d; }
	bool operator==(const _DataType &d2) const { return d == dynamic_cast<const _StringType &>(d2).d; }
	string to_string() const { return d; }
	void dump(char* p) const { d.copy(p, m_size); } 
};


pair<DataType, int> eType(pair<std::string, int> type);
