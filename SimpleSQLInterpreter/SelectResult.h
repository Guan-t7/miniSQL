#pragma once
#include <vector>
#include "DBInfo.h"
#include "QueryResult.h"
class SelectResult :
	public QueryResult {
public:
	std::string print() override;
private:
	TableInfo tableInfo; //? 为什么需要返回这个
	std::vector<std::vector<std::string>> data;
};

enum opType { E, NE, L, G, LE, GE }op; // rel_op, ref. x86 asm
struct Condition {
	std::string col, val;
	opType op;
	
	Condition(string _col, opType _op, string _val): col(_col),op(_op),val(_val){}
};
