#pragma once
#include <string>

class Interpreter {
public:
	static int quitStatement();
	static int execfileStatement(std::string filename);
	static int mainLoop();
	static void handleResult(int result);
	static int mode;
};

