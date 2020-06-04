#include "DBExecutor.h"
#include "RecordManager.h"

#include <algorithm>
#include <set>

#include "CatalogManager.h"
#include "error.h"
#include "IndexManager.h"


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
	/* TODO: use index*/
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
	result.setSuccess(tableInfo, rm.select(tableName, conds));
	return result;
}

QueryResult DBExecutor::deleteQuery(std::string tableName, std::vector<Condition> conds) {
	/* TODO: use index*/
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
}

QueryResult DBExecutor::createTableQuery(TableInfo info) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(info.name);
	if (!tableInfo.name.empty()) return EXISTING_TABLE_NAME;
	bool primaryKeyFound = false || info.primaryKey.empty();
	std::set<std::string> usedName;
	std::pair<std::string, int> ptype;
	for (const auto& metadata : info.metadata) {
		if (info.primaryKey == metadata.name) {
			primaryKeyFound = true;
			ptype = metadata.type;
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
			IndexInfo pi;
			pi.columnName = info.primaryKey;
			pi.indexName = info.name + "PKIndex";
			pi.tableName = info.name;
			IndexManager im;
			im.createIndex(pi.indexName, pi.tableName, pi.columnName, toIMType(ptype));
			auto indexInfos = CatalogManager::getIndex();
			indexInfos.indexInfos.emplace_back(pi);
			CatalogManager::updateIndex(indexInfos);
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
	auto pos = std::find_if(tableInfo.metadata.begin(), tableInfo.metadata.end(),
		[&info](const Column& i) {return i.name == info.columnName; });
	if (pos != tableInfo.metadata.end()) {
		indexInfos.indexInfos.emplace_back(info);
		IndexManager im;
		im.createIndex(info.indexName, info.tableName, info.columnName, toIMType(pos->type));
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
	rm.insert(tableName, values);
	auto indexInfos = checkIndex(tableName);
	result.setSuccess(0);
	return result;
}

QueryResult DBExecutor::dropTableQuery(std::string tableName) {
	QueryResult result(SUCCESS);
	const auto tableInfo = CatalogManager::getTableInfo(tableName);
	if (tableInfo.name.empty()) return NOT_EXISTING_TABLE_NAME;
	auto indexInfo = CatalogManager::getIndex();
	IndexManager im;
	for (auto iter = indexInfo.indexInfos.begin(); iter != indexInfo.indexInfos.end();) {
		if (iter->tableName == tableName) {
			im.dropIndex(iter->indexName);
			iter = indexInfo.indexInfos.erase(iter);
		} else {
			++iter;
		}
	}
	CatalogManager::updateIndex(indexInfo);
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
	IndexManager im;
	im.dropIndex(indexName);
	CatalogManager::updateIndex(indexInfos);
	result.setSuccess(0);
	return result;
}

IndexInfo DBExecutor::checkIndex(std::string tableName, std::string columnName) {
	auto indexInfos = CatalogManager::getIndex();
	for (auto index : indexInfos.indexInfos) {
		if (index.columnName == columnName && index.tableName == tableName) return index;
	}
	return {};
}

std::vector<IndexInfo> DBExecutor::checkIndex(std::string tableName) {
	std::vector<IndexInfo> infos;
	auto indexInfos = CatalogManager::getIndex();
	for (auto index : indexInfos.indexInfos) {
		if (index.tableName == tableName) infos.emplace_back(index);
	}
	return infos;
}

int toIMType(std::pair<std::string, int> type) {
	if (type.first == "int") return IndexManager::TYPE_INT;
	if (type.first == "float") return IndexManager::TYPE_FLOAT;
	return type.second;
}