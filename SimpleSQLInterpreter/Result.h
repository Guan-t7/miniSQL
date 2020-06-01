#pragma once
#include <string>

class Result {
public:
	Result();
	Result(int);
	virtual ~Result() = default;
	int getStatus() const;
	int operator =(int newStatus);
	virtual std::string print();
protected:
	int status;
};

