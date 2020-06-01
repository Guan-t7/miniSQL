#include "CatalogManager.h"
#include "error.h"

TableInfo CatalogManager::getTableInfo(const std::string& tableName) {
	if (true/*TODO:successfully fetch file*/) {
		const std::string s = std::string(reinterpret_cast<const char*>(""));
		std::istringstream is(s);
		return TableInfo::parseString(is);
	} else {
		return {};
	}
}

int CatalogManager::updateIndex(IndexInfos indexInfos) {
	std::string s = indexInfos.toString();
	/*TODO:write some data*/
	return SUCCESS;
}

IndexInfos CatalogManager::getIndex() {
	if (true/*TODO:successfully fetch file*/) {
		const std::string s = std::string(reinterpret_cast<const char*>(""));
		std::istringstream is(s);
		return IndexInfos::parseString(is);
	} else {
		return {};
	}
}

int CatalogManager::updateTableInfo(TableInfo tableInfo) {
	std::string s = tableInfo.toString();
	/*TODO:write some data*/
	return SUCCESS;
}

int CatalogManager::dropTable(const std::string& tableName){
	const auto filename = tableName + ".tbl";
	const auto result = ::remove(filename.c_str());
	return result==0?0:DELETE_TABLE_FAILED;
}
