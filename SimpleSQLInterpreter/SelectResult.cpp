#include "SelectResult.h"

std::string SelectResult::print() {
	std::string s{};
	if (getStatus() == 0) {
		//calculate padding
		std::vector<int> padding;
		const int columnCount = tableInfo.metadata.size();
		padding.resize(columnCount);
		std::fill(padding.begin(), padding.end(), 10);
		for (int i = 0; i < data.size(); i++) {
			for (int j = 0; j < columnCount; j++) {
				if (padding[j] < data[i][j].length()) padding[j] = data[i][j].length();
			}
		}
		for (int i = 0; i < columnCount; i++) {
			int len = tableInfo.metadata[i].name.length();
			if (len > padding[i]) padding[i] = len;
			s += tableInfo.metadata[i].name + std::string(padding[i] - len + 2, ' ');
		}
		s += '\n';
		for (auto& i : data) {
			for (int j = 0; j < columnCount; j++) {
				s += i[j] + std::string(padding[j] - i[j].length() + 2, ' ');
			}
			s += '\n';
		}
		s += "Query success. " + std::to_string(count) + " rows in set. " + std::to_string(getDuration() / 1000.0) + " seconds taken.\n";
		return s;
	} else {
		return QueryResult::print();
	}
}

SelectResult::SelectResult(int v) :QueryResult(v) {
}

void SelectResult::setSuccess(TableInfo tableInfo, std::vector<std::vector<std::string>> data) {
	QueryResult::setSuccess(data.size());
	this->tableInfo = std::move(tableInfo);
	this->data = std::move(data);
}

std::string to_string(opType e) {
	switch (e) {
	case opType::E: return "E";
	case opType::NE: return "NE";
	case opType::L: return "L";
	case opType::G: return "G";
	case opType::LE: return "LE";
	case opType::GE: return "GE";
	default: return "unknown";
	}
}
