#include "DBExecutor.h"

#include <algorithm>
#include <set>

#include "CatalogManager.h"
#include "error.h"

QueryResult DBExecutor::createTableQuery(TableInfo info) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(info.name);
	if (!tableInfo.name.empty()) return EXISTING_TABLE_NAME;
	bool primaryKeyFound = false || info.primaryKey.empty();
	std::set<std::string> usedName;
	for (const auto& metadata : info.metadata) {
		if (info.primaryKey == metadata.name) {
			primaryKeyFound = true;
			if (!metadata.unique) {
				return NON_UNIQUE_PRIMARY_KEY;
			}
		}
		if (metadata.type.first == "char") {
			if (metadata.type.second < 0 || metadata.type.second>255) {
				return MAX_CHAR_LENGTH_EXCEEDED;
			}
		}
		if (usedName.count(metadata.name)) return EXISTING_COLUMN_NAME;
		usedName.insert(metadata.name);
	}
	if (primaryKeyFound) {
		if (!info.primaryKey.empty()) {
			/*TODO: inform the index manager?*/
		}
	} else {
		return UNKNOWN_PRIMARY_KEY;
	}
	CatalogManager::updateTableInfo(info);
	return result;
}

QueryResult DBExecutor::createIndexQuery(IndexInfo info) {
	QueryResult result(SUCCESS);
	auto indexInfos = CatalogManager::getIndex();
	if (std::any_of(indexInfos.indexInfos.begin(), indexInfos.indexInfos.end(),
		[&info](const IndexInfo& i) {return i.indexName == info.indexName; })) {
		return EXISTING_INDEX_NAME;
	}
	auto tableInfo = CatalogManager::getTableInfo(info.tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	if (std::any_of(tableInfo.metadata.begin(), tableInfo.metadata.end(),
		[&info](const Column& i) {return i.name == info.columnName; })) {
		indexInfos.indexInfos.emplace_back(info);
		/*TODO: call index manager*/
		CatalogManager::updateIndex(indexInfos);
	} else {
		return NOT_EXISTING_COLUMN_NAME;
	}
	return result;
}

QueryResult DBExecutor::dropTableQuery(std::string tableName) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	auto indexInfo = CatalogManager::getIndex();
	indexInfo.indexInfos.erase(std::remove_if(indexInfo.indexInfos.begin(), indexInfo.indexInfos.end(),
		[&tableName](const IndexInfo& info) {return info.tableName == tableName; }), indexInfo.indexInfos.end());
	CatalogManager::updateIndex(indexInfo);
	CatalogManager::dropTable(tableName);
	return result;
}

QueryResult DBExecutor::dropIndexQuery(std::string indexName) {
	QueryResult result(SUCCESS);
	auto indexInfos = CatalogManager::getIndex();
	const auto pos = std::find_if(indexInfos.indexInfos.begin(), indexInfos.indexInfos.end(),
	                           [&indexName](const IndexInfo& i) {return i.indexName == indexName; });
	if (pos == indexInfos.indexInfos.end()) {
		return NOT_EXISTING_INDEX_NAME;
	}
	indexInfos.indexInfos.erase(pos);
	CatalogManager::updateIndex(indexInfos);
	return result;
}
