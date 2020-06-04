#include "QueryResult.h"

QueryResult::QueryResult() {
	startTime = std::chrono::system_clock::now();
	count = 0;
	duration = 0;
}

QueryResult::QueryResult(int c):Result(c){
	startTime = std::chrono::system_clock::now();
	count = 0;
	duration = 0;
}

void QueryResult::setSuccess(int cnt) {
	status = 0;
	count = cnt;
	const auto now = std::chrono::system_clock::now();
	duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - startTime).count();
}

int QueryResult::getCount() const {
	return count;
}

int QueryResult::getDuration() const {
	return duration;
}

std::string QueryResult::print() {
	std::string s{};
	if (getStatus() == 0) {//success
		s += "Query success. " + std::to_string(count) + " rows affected. " + std::to_string(getDuration() / 1000.0) + " seconds taken.\n";
	}else
	{
		s = "Error occurs when executing query: " ;
	}
	return s;
}
