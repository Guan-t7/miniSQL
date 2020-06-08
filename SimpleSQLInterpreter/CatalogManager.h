#pragma once
#include "DBInfo.h"

class CatalogManager {
public:
	static TableDsc getTableInfo(const std::string& tableName);
	static int updateIndex(IndexDscs indexInfo);
	static IndexDscs getIndex();
	static int updateTableInfo(TableDsc tableInfo);
	static int dropTable(const std::string& tableName);
};

