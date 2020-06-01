#pragma once
#include <sstream>
#include <string>
#include <vector>

enum DataType {
	IntType,
	FloatType,
	StringType
};

// All names shall be no longer than 20 characters
struct Column {
	std::string name;
	std::pair<std::string, int> type;
	bool unique;
	static Column parseString(std::istringstream& s) {
		Column ret;
		s >> ret.name;
		s >> ret.type.first;
		s >> ret.type.second;
		s >> ret.unique;
		return ret;
	}
	std::string toString() {
		return name + " " + type.first + " " + std::to_string(type.second) + " " + std::to_string(unique);
	}
};

struct IndexInfo {
	std::string tableName;
	std::string indexName;
	std::string columnName;
	static IndexInfo parseString(std::istringstream& s) {
		IndexInfo ret;
		s >> ret.tableName;
		s >> ret.indexName;
		s >> ret.columnName;
		return ret;
	}
	std::string toString() {
		return tableName + " " + indexName + " " + columnName;
	}
};

struct IndexInfos {
	std::vector<IndexInfo> indexInfos;
	static IndexInfos parseString(std::istringstream& s) {
		IndexInfos ret;
		int count;
		s >> count;
		for(int i=0;i<count;i++)
		{
			ret.indexInfos.emplace_back(IndexInfo::parseString(s));
		}
		return ret;
	}
	std::string toString() {
		std::string s = std::to_string(indexInfos.size())+ " ";
		for (int i = 0; i < indexInfos.size(); i++) {
			s += indexInfos[i].toString() + " ";
		}
		return s;
	}
};
// This will not go larger than 4096B so no more paging consideration, damn
struct TableInfo {
	std::string name;
	std::vector<Column> metadata;
	std::string primaryKey;
	static TableInfo parseString(std::istringstream& s) {
		TableInfo ret;
		int columnCount;
		s >> ret.name;
		s >> columnCount;
		for (int i = 0; i < columnCount; i++) {
			ret.metadata.emplace_back(Column::parseString(s));
		}
		s >> ret.primaryKey;
		return ret;
	}
	std::string toString() {
		std::string s;
		s = name + " " + std::to_string(metadata.size()) + " ";
		for (int i = 0; i < metadata.size(); i++) {
			s += metadata[i].toString() + " ";
		}
		s += primaryKey + " ";
		return s;
	}
};
