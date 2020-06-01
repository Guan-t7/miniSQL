#include "SelectResult.h"

std::string SelectResult::print() {
	std::string s{};
	if (getStatus() == 0) {
		for (auto& i : tableInfo.metadata) {
			s += i.name + " | ";
		}
		const int columnCount = tableInfo.metadata.size();
		s += '\n';
		for (auto& i : data) {
			for (int j = 0; j < columnCount; j++) {
				s += i[j] + "   ";
			}
			s += '\n';
		}
		s += "Query success. " + std::to_string(count) + " rows in set. " + std::to_string(getDuration() / 1000.0) + " seconds taken.\n";
		return s;
	} else {
		return QueryResult::print();
	}
}
