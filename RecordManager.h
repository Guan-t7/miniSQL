#pragma once
#include "BufferManager.h"
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

	_DataType * mk_obj(std::pair<DataType, int>& type, const void * mp_record);
	_DataType * mk_obj(std::pair<DataType, int>& type, const string& val);
	bool cond_fit(Condition & c, _DataType * data, _DataType * cond_val);
	void insert_page(std::string & tableName, size_t i, unsigned int rec_size, _DataType * dataArr[]);
	vector<p_Entry> sel_(string tableName, vector<Condition> conds, vector<p_Entry> hint);

public:
	RecordManager();
	~RecordManager();
	// 0 for success
	int create_table(string tableName); 
	int drop_table(string tableName);
	vector<vector<string>> select (string tableName, vector<Condition> conds); //? Column是否能保证字段的顺序
		// vector<vector<string>> select (const string &tableName, const vector<Condition> &conds);
	int insert(string tableName, std::vector<std::string> s_vals); 	//todo I have p_Entry for index insert
	//! this one returns count of records deleted
	int delete_rec(string tableName, vector<Condition> conds);
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
class _StringType : public _DataType
{
	string d;
	size_t m_size;
public:
	_StringType(string val) :d(val), m_size(val.size()) {}
	_StringType(const void* p, size_t size) :d((char*)p, (char*)p + size), m_size(size) {}
	size_t size() const { return m_size; }
	bool operator<(const _DataType &d2) const { return d < dynamic_cast<const _StringType &>(d2).d; }
	bool operator==(const _DataType &d2) const { return d == dynamic_cast<const _StringType &>(d2).d; }
	string to_string() const { return d; }
	void dump(char* p) const { d.copy(p, m_size); } //todo can be modified to adapt varchar
};


pair<DataType, int> eType(pair<std::string, int> type);
