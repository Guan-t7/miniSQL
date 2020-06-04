#pragma once
#include <vector>
#include "DBInfo.h"
#include "QueryResult.h"
class SelectResult :
	public QueryResult {
public:
	std::string print() override;
	SelectResult(int);
	void setSuccess(TableInfo tableInfo, std::vector<std::vector<std::string>> data);
private:
	TableInfo tableInfo; //? 为什么需要返回这个 re:不然没格式没法输出到屏幕上
	std::vector<std::vector<std::string>> data;
};

enum class opType { E, NE, L, G, LE, GE };

std::string to_string(opType e); // rel_op, ref. x86 asm
struct Condition {
	std::string col, val;
	opType op;
	
	Condition(std::string _col, opType _op, std::string _val): col(_col),op(_op),val(_val){}
};
