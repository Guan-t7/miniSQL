#pragma once
#include "DBInfo.h"

class CatalogManager {
public:
	static TableInfo getTableInfo(const std::string& tableName);
	static int updateIndex(IndexInfos indexInfo);
	static IndexInfos getIndex();
	static int updateTableInfo(TableInfo tableInfo);
	static int dropTable(const std::string& tableName);
};

