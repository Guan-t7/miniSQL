#include "Parser.h"

#include <ANTLRInputStream.h>

#include "ErrorListener.h"
#include "SQLVisitor.h"
#include "interpreter/cpp/sqlLexer.h"
#include "interpreter/cpp/sqlParser.h"

class ErrorListener;

int Parser::parseString(std::string str) {
	antlr4::ANTLRInputStream stream = antlr4::ANTLRInputStream(str);

	// Give the input to the lexer.
	sqlLexer lexer(&stream);
	lexer.removeErrorListeners();
	auto el = std::make_shared<ErrorListener>();
	lexer.addErrorListener(el.get());
	// Generate the tokens.
	antlr4::CommonTokenStream tokens(&lexer);

	tokens.fill();

	// Create the translation that will parse the input.
	sqlParser parser(&tokens);
	parser.setBuildParseTree(true);
	parser.removeErrorListeners();
	parser.addErrorListener(el.get());
	sqlParser::RootContext* tree = parser.root();

	auto visitor = SQLVisitor();
	try {
		auto result = visitor.visitRoot(tree);
		if (result.isNotNull()) return result;
		else return UNKNOWN_ERROE_WHEN_PARSING;
	} catch (...) {
		return UNKNOWN_ERROE_WHEN_PARSING;
	}

}
