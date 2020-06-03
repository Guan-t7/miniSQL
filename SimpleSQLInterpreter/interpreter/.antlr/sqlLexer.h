
// Generated from d:\work\personal\2020DB\miniSQL\SimpleSQLInterpreter\interpreter\sqlLexer.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  sqlLexer : public antlr4::Lexer {
public:
  enum {
    SPACE = 1, SPEC_MYSQL_COMMENT = 2, COMMENT_INPUT = 3, LINE_COMMENT = 4, 
    SELECT = 5, INSERT = 6, DELETE = 7, DROP = 8, CREATE = 9, QUIT = 10, 
    EXECFILE = 11, TABLE = 12, INDEX = 13, WILDCARD = 14, FROM = 15, INTO = 16, 
    ON = 17, QUOTE = 18, OPEN_BRACKET = 19, CLOSE_BRACKET = 20, WHERE = 21, 
    AND = 22, OR = 23, NOT_EQUAL = 24, SMALLER_EQUAL = 25, GREATER_EQUAL = 26, 
    SMALLER = 27, GREATER = 28, EQUAL = 29, CHAR = 30, INT = 31, FLOAT = 32, 
    UNIQUE = 33, DECIMAL_LITERAL = 34, STRING_LITERAL = 35, REAL_LITERAL = 36, 
    PRIMARY_KEY = 37, VALUES = 38, COMMA = 39, SEMICOLON = 40, DQUOTA_STRING = 41, 
    TOKEN = 42, ERROR_RECONGNIGION = 43
  };

  enum {
    ERRORCHANNEL = 2, MYSQLCOMMENT = 3
  };

  sqlLexer(antlr4::CharStream *input);
  ~sqlLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

