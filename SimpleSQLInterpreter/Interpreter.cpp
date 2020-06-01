#include "Interpreter.h"
#include <fstream>
#include <iostream>
#include "error.h"
#include "Parser.h"

int Interpreter::quitStatement() {
	return EXIT;
}

int Interpreter::execfileStatement(std::string filename) {
	std::ifstream ifile(filename);
	std::string s((std::istreambuf_iterator<char>(ifile)),
		std::istreambuf_iterator<char>());
	const int result = Parser::parseString(s);
	return result;
}

int Interpreter::mainLoop() {
	int result = SUCCESS;
	std::cout << "Minisql alpha version" << std::endl;
	while (result != EXIT) {
		std::cout << "> ";
		std::string s;
		std::getline(std::cin, s,';');
		s += ';';
		result = Parser::parseString(s);
		handleResult(result);
	}
	std::cout << "Bye" << std::endl;
	return SUCCESS;
}

void Interpreter::handleResult(int result) {
	switch (result) {
	case NOT_EXISTING_TABLE_NAME:
		std::cout << "Not existing table name" << std::endl;
		break;
	case UNKNOWN_ERROE_WHEN_PARSING:
		//Should be handled by error listener
		break;
	case EXISTING_TABLE_NAME:
		std::cout << "Existing table name" << std::endl;
		break;
	case NOT_EXISTING_COLUMN_NAME:
		std::cout << "Not existing column name" << std::endl;
		break;
	case EXISTING_COLUMN_NAME:
		std::cout << "Existing column name" << std::endl;
		break;
	case NOT_EXISTING_INDEX_NAME:
		std::cout << "Not existing index name" << std::endl;
		break;
	case EXISTING_INDEX_NAME:
		std::cout << "Existing index name" << std::endl;
		break;
	case MAX_CHAR_LENGTH_EXCEEDED:
		std::cout << "Max char length exceeded" << std::endl;
		break;
	case UNKNOWN_PRIMARY_KEY:
		std::cout << "Unknown primary key" << std::endl;
		break;
	case DELETE_TABLE_FAILED:
		std::cout << "Delete table failed" << std::endl;
		break;
	case SUCCESS:
		//OK, nothing happens
		break;
	default:
		std::cout << "An unknown error occurs" << std::endl;
		break;
	}
}
