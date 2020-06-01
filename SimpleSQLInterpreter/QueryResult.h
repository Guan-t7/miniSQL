#pragma once
#include <chrono>
#include "Result.h"

class QueryResult:public Result {
public:
	QueryResult();
	QueryResult(int);
	void setSuccess(int cnt);
	int getCount() const;
	int getDuration() const;
	std::string print() override;
protected:
	int count;
	std::chrono::time_point<std::chrono::system_clock> startTime;
	int duration;
};

