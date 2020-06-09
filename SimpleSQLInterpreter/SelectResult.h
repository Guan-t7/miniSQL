#pragma once
#include <vector>
#include "DBInfo.h"
#include "QueryResult.h"
class SelectResult :
	public QueryResult {
public:
	std::string print() override;
	SelectResult(int);
	void setSuccess(TableDsc tableInfo, std::vector<std::vector<std::string>> data);
private:
	TableDsc tableInfo;
	std::vector<std::vector<std::string>> data;
};

enum class opType { E, NE, L, G, LE, GE };

std::string to_string(opType e); // rel_op, ref. x86 asm
struct Condition {
	std::string col, val;
	opType op;
	
	Condition(std::string _col, opType _op, std::string _val): col(_col),op(_op),val(_val){}
};
