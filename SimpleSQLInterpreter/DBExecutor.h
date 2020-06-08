#pragma once
#include "QueryResult.h"
#include "SelectResult.h"

class DBExecutor {
public:
	static SelectResult selectQuery(std::string tableName, std::vector<Condition> conds);
	static QueryResult deleteQuery(std::string tableName, std::vector<Condition> conds);
	static QueryResult createTableQuery(TableDsc info);
	static QueryResult createIndexQuery(IndexDsc info);
	static QueryResult insertQuery(std::string tableName,std::vector<std::string>);
	static QueryResult dropTableQuery(std::string tableName);
	static QueryResult dropIndexQuery(std::string indexName);
private:
	static IndexDsc checkIndex(std::string tableName, std::string columnName);
	static std::vector<IndexDsc> checkIndex(std::string tableName);
	static int toIMType(std::pair<std::string, int> type);
};

