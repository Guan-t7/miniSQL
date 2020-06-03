#pragma once
#include <vector>
#include "DBInfo.h"
#include "QueryResult.h"
class SelectResult :
	public QueryResult {
public:
	std::string print() override;
private:
	TableInfo tableInfo;
	std::vector<std::vector<std::string>> data;
};

struct Condition {
	std::string col, val;

	enum opType { E, NE, L, G, LE, GE }op; // rel_op, ref. x86 asm
};
