#include "Result.h"
#include "error.h"

Result::Result(){
	status = SUCCESS;
}

Result::Result(int c){
	status = c;
}

int Result::getStatus() const {
	return status;
}

int Result::operator=(int newStatus){
	return this->status = newStatus;
}

std::string Result::print()
{
	std::string s{};
	if (getStatus() == 0) {//success
		s += "Query success.\n";
	} else {
		s = "Error occurs when executing query ";
	}
	return s;
}
