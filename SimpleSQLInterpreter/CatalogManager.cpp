#include "CatalogManager.h"

#include <fstream>

#include "error.h"
#include "BufferManager.h"
TableDsc CatalogManager::getTableInfo(const std::string& tableName) {
	const auto filename = "table/" + tableName + ".tbl";
	ifstream file(filename);
	if (!file.fail()) {
		const std::string s((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());
		std::istringstream is(s);
		return TableDsc::parseString(is);
	} else {
		return {};
	}
}

int CatalogManager::updateIndex(IndexDscs indexInfos) {
	std::string s = indexInfos.toString();
	ofstream indexFile("all.idx", std::ofstream::trunc);
	indexFile << s;
	return SUCCESS;
}

IndexDscs CatalogManager::getIndex() {
	ifstream indexFile("all.idx");
	if (!indexFile.fail()) {
		const std::string s((std::istreambuf_iterator<char>(indexFile)),
			std::istreambuf_iterator<char>());
		std::istringstream is(s);
		return IndexDscs::parseString(is);
	} else {
		return {};
	}
}

int CatalogManager::updateTableInfo(TableDsc tableInfo) {
	const auto filename = "table/" + tableInfo.name + ".tbl";
	std::string s = tableInfo.toString();
	ofstream file(filename, std::ofstream::trunc);
	file << s;
	return SUCCESS;
}

int CatalogManager::dropTable(const std::string& tableName) {
	const auto filename = "table/" + tableName + ".tbl";
	const auto result = ::remove(filename.c_str());
	return result == 0 ? 0 : DELETE_TABLE_FAILED;
}
