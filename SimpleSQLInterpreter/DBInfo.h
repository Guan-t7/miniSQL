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

struct IndexDsc {
	std::string tableName;
	std::string indexName;
	std::string columnName;
	static IndexDsc parseString(std::istringstream& s) {
		IndexDsc ret;
		s >> ret.tableName;
		s >> ret.indexName;
		s >> ret.columnName;
		return ret;
	}
	std::string toString() {
		return tableName + " " + indexName + " " + columnName;
	}
};

struct IndexDscs {
	std::vector<IndexDsc> indexInfos;
	static IndexDscs parseString(std::istringstream& s) {
		IndexDscs ret;
		int count;
		s >> count;
		for(int i=0;i<count;i++)
		{
			ret.indexInfos.emplace_back(IndexDsc::parseString(s));
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
struct TableDsc {
	std::string name;
	std::vector<Column> metadata;
	std::string primaryKey;
	static TableDsc parseString(std::istringstream& s) {
		TableDsc ret;
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
