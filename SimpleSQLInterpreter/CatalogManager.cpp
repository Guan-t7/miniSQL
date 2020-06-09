#include "CatalogManager.h"

#include <fstream>

#include "error.h"
#include "BufferManager.h"

std::map<std::string, TableInfo> CatalogManager::cachedTableInfos = {};
IndexInfos CatalogManager::cachedIndexInfos = {};

TableInfo CatalogManager::getTableInfo(const std::string& tableName) {
	if (cachedTableInfos.count(tableName) != 0) return cachedTableInfos[tableName];
	const auto filename = "table/" + tableName + ".tbl";
	ifstream file(filename);
	if (!file.fail()) {
		const std::string s((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
		std::istringstream is(s);
		auto t = TableInfo::parseString(is);
		cachedTableInfos[tableName] = t;
		return t;
	} else {
		return {};
	}
}

int CatalogManager::updateIndex(IndexInfos indexInfos) {
	cachedIndexInfos = indexInfos;
	std::string s = indexInfos.toString();
	ofstream indexFile("all.idx", std::ofstream::trunc);
	indexFile << s;
	return SUCCESS;
}

IndexInfos CatalogManager::getIndex() {
	if (!cachedIndexInfos.indexInfos.empty()) return cachedIndexInfos;
	ifstream indexFile("all.idx");
	if (!indexFile.fail()) {
		const std::string s((std::istreambuf_iterator<char>(indexFile)),
			std::istreambuf_iterator<char>());
		std::istringstream is(s);
		auto t = IndexInfos::parseString(is);
		cachedIndexInfos = t;
		return t;
	} else {
		return {};
	}
}

int CatalogManager::updateTableInfo(TableInfo tableInfo) {
	cachedTableInfos[tableInfo.name] = tableInfo;
	const auto filename = "table/" + tableInfo.name + ".tbl";
	std::string s = tableInfo.toString();
	ofstream file(filename, std::ofstream::trunc);
	file << s;
	return SUCCESS;
}

int CatalogManager::dropTable(const std::string& tableName) {
	if (cachedTableInfos.count(tableName)) cachedTableInfos.erase(tableName);
	const auto filename = "table/" + tableName + ".tbl";
	const auto result = ::remove(filename.c_str());
	return result == 0 ? 0 : DELETE_TABLE_FAILED;
}
