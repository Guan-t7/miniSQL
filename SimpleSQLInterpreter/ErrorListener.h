#pragma once
#include <ANTLRErrorListener.h>

class ErrorListener :public antlr4::ANTLRErrorListener {
	void syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line,
		size_t charPositionInLine, const std::string& msg, std::exception_ptr e) override {
		// I mix up lexer and parser, hope that I won't get cursed by John Backus
		std::cout << "Syntax Error near line " << line << " position " << charPositionInLine << std::endl;
		std::cout << msg << std::endl;

	}
	void reportAmbiguity(antlr4::Parser* recognizer, const antlr4::dfa::DFA& dfa, size_t startIndex, size_t stopIndex, bool exact,
		const antlrcpp::BitSet& ambigAlts, antlr4::atn::ATNConfigSet* configs) override {

	};

	void reportAttemptingFullContext(antlr4::Parser* recognizer, const antlr4::dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
		const antlrcpp::BitSet& conflictingAlts, antlr4::atn::ATNConfigSet* configs) override {

	};

	void reportContextSensitivity(antlr4::Parser* recognizer, const antlr4::dfa::DFA& dfa, size_t startIndex, size_t stopIndex,
		size_t prediction, antlr4::atn::ATNConfigSet* configs) override {
	};
};

