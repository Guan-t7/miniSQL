#include "DBExecutor.h"
#include "RecordManager.h"

#include <algorithm>
#include <set>

#include "CatalogManager.h"
#include "error.h"


int validateDataType(std::string data, std::pair<std::string, int> type) {
	bool success = true;
	if (type.first == "int") {
		size_t pos;
		try {
			int n = std::stoi(data, &pos);
			if (pos != data.length()) success = false;
		} catch (...) {
			success = false;
		}
	}
	if (type.first == "float") {
		size_t pos;
		try {
			float n = std::stof(data, &pos);
			if (pos != data.length()) success = false;
		} catch (...) {
			success = false;
		}
	}
	if (success == false) return BAD_VALUE;
	if (type.first == "char") {
		if (data.size() > type.second) success = false;
	}
	if (success == false) return MAX_CHAR_LENGTH_EXCEEDED;
	return SUCCESS;
}

SelectResult DBExecutor::selectQuery(std::string tableName, std::vector<Condition> conds) {
	SelectResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	for (auto cond : conds) {
		Column refCol{};
		for (auto col : tableInfo.metadata) {
			if (col.name == cond.col) refCol = col;
		}
		if (refCol.name.empty()) return NOT_EXISTING_COLUMN_NAME;
		int ret;
		if ((ret = validateDataType(cond.val, refCol.type)) != SUCCESS) return ret;
	}
	RecordManager rm;
	result.setSuccess(tableInfo,rm.select(tableName, conds));
	return result;
	/*TODO: call index manager*/
}

QueryResult DBExecutor::deleteQuery(std::string tableName, std::vector<Condition> conds) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	for (auto cond : conds) {
		Column refCol{};
		for (auto col : tableInfo.metadata) {
			if (col.name == cond.col) refCol = col;
		}
		if (refCol.name.empty()) return NOT_EXISTING_COLUMN_NAME;
		int ret;
		if ((ret = validateDataType(cond.val, refCol.type)) != SUCCESS) return ret;
	}
	RecordManager rm;
	result.setSuccess(rm.delete_rec(tableName, conds));
	return result;
	/*TODO: call index manager*/
}

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
			/*TODO: call index manager*/
		}
	} else {
		return UNKNOWN_PRIMARY_KEY;
	}
	RecordManager rm;
	rm.create_table(info.name);
	CatalogManager::updateTableInfo(info);
	result.setSuccess(0);
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
	result.setSuccess(0);
	return result;
}

QueryResult DBExecutor::insertQuery(std::string tableName, std::vector<std::string> values) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	if (values.size() != tableInfo.metadata.size()) return WRONG_VALUE_COUNT;
	for (int i = 0; i < values.size(); i++) {
		int ret;
		if ((ret = validateDataType(values[i], tableInfo.metadata[i].type)) != SUCCESS) {
			return ret;
		}
	}
	RecordManager rm;
	auto res = rm.insert(tableName, values);
	if (res != 0) return res;
	result.setSuccess(1);
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
	/*TODO: call index manager*/
	CatalogManager::dropTable(tableName);
	RecordManager rm;
	rm.drop_table(tableName);
	result.setSuccess(0);
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
	/*TODO: call index manager*/
	CatalogManager::updateIndex(indexInfos);
	result.setSuccess(0);
	return result;
}
