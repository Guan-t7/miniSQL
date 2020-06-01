#pragma once
#include "QueryResult.h"
#include "SelectResult.h"

class DBExecutor {
public:
	static SelectResult selectQuery(std::string tableName, std::vector<Condition> conds);
	static QueryResult deleteQuery(std::string tableName, std::vector<Condition> conds);
	static QueryResult createTableQuery(TableInfo info);
	static QueryResult createIndexQuery(IndexInfo info);
	static QueryResult insertQuery(std::string tableName,std::vector<std::string>);
	static QueryResult dropTableQuery(std::string tableName);
	static QueryResult dropIndexQuery(std::string indexName);
};

