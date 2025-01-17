
// Generated from sqlParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  sqlParser : public antlr4::Parser {
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
    RuleRoot = 0, RuleSqlStatements = 1, RuleSqlStatement = 2, RuleEmptyStatement = 3, 
    RuleSelectQuery = 4, RuleSelectTarget = 5, RuleOptionalWhereClause = 6, 
    RuleWhereClause = 7, RuleWhereConditions = 8, RuleWhereCondition = 9, 
    RuleWhereOP = 10, RuleDropIndexQuery = 11, RuleDropTableQuery = 12, 
    RuleCreateIndexQuery = 13, RuleCreateTableQuery = 14, RuleColumnDefinitions = 15, 
    RuleColumnDefinition = 16, RulePrimaryKeyDefinition = 17, RuleInsertQuery = 18, 
    RuleLiteralValues = 19, RuleDeleteQuery = 20, RuleQuitStatement = 21, 
    RuleExecfileStatement = 22, RuleTableName = 23, RuleColumnName = 24, 
    RuleIndexName = 25, RuleLiteral = 26, RuleOp = 27, RuleType = 28, RuleCharType = 29
  };

  sqlParser(antlr4::TokenStream *input);
  ~sqlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class RootContext;
  class SqlStatementsContext;
  class SqlStatementContext;
  class EmptyStatementContext;
  class SelectQueryContext;
  class SelectTargetContext;
  class OptionalWhereClauseContext;
  class WhereClauseContext;
  class WhereConditionsContext;
  class WhereConditionContext;
  class WhereOPContext;
  class DropIndexQueryContext;
  class DropTableQueryContext;
  class CreateIndexQueryContext;
  class CreateTableQueryContext;
  class ColumnDefinitionsContext;
  class ColumnDefinitionContext;
  class PrimaryKeyDefinitionContext;
  class InsertQueryContext;
  class LiteralValuesContext;
  class DeleteQueryContext;
  class QuitStatementContext;
  class ExecfileStatementContext;
  class TableNameContext;
  class ColumnNameContext;
  class IndexNameContext;
  class LiteralContext;
  class OpContext;
  class TypeContext;
  class CharTypeContext; 

  class  RootContext : public antlr4::ParserRuleContext {
  public:
    RootContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    SqlStatementsContext *sqlStatements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RootContext* root();

  class  SqlStatementsContext : public antlr4::ParserRuleContext {
  public:
    SqlStatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SqlStatementContext *> sqlStatement();
    SqlStatementContext* sqlStatement(size_t i);
    std::vector<EmptyStatementContext *> emptyStatement();
    EmptyStatementContext* emptyStatement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SqlStatementsContext* sqlStatements();

  class  SqlStatementContext : public antlr4::ParserRuleContext {
  public:
    SqlStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SelectQueryContext *selectQuery();
    DropIndexQueryContext *dropIndexQuery();
    DropTableQueryContext *dropTableQuery();
    CreateIndexQueryContext *createIndexQuery();
    CreateTableQueryContext *createTableQuery();
    InsertQueryContext *insertQuery();
    DeleteQueryContext *deleteQuery();
    QuitStatementContext *quitStatement();
    ExecfileStatementContext *execfileStatement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SqlStatementContext* sqlStatement();

  class  EmptyStatementContext : public antlr4::ParserRuleContext {
  public:
    EmptyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStatementContext* emptyStatement();

  class  SelectQueryContext : public antlr4::ParserRuleContext {
  public:
    SelectQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SELECT();
    antlr4::tree::TerminalNode *WILDCARD();
    antlr4::tree::TerminalNode *FROM();
    SelectTargetContext *selectTarget();
    OptionalWhereClauseContext *optionalWhereClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectQueryContext* selectQuery();

  class  SelectTargetContext : public antlr4::ParserRuleContext {
  public:
    SelectTargetContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TableNameContext *tableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SelectTargetContext* selectTarget();

  class  OptionalWhereClauseContext : public antlr4::ParserRuleContext {
  public:
    OptionalWhereClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    WhereClauseContext *whereClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OptionalWhereClauseContext* optionalWhereClause();

  class  WhereClauseContext : public antlr4::ParserRuleContext {
  public:
    WhereClauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHERE();
    WhereConditionsContext *whereConditions();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereClauseContext* whereClause();

  class  WhereConditionsContext : public antlr4::ParserRuleContext {
  public:
    WhereConditionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<WhereConditionContext *> whereCondition();
    WhereConditionContext* whereCondition(size_t i);
    std::vector<WhereOPContext *> whereOP();
    WhereOPContext* whereOP(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereConditionsContext* whereConditions();

  class  WhereConditionContext : public antlr4::ParserRuleContext {
  public:
    WhereConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ColumnNameContext *columnName();
    OpContext *op();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereConditionContext* whereCondition();

  class  WhereOPContext : public antlr4::ParserRuleContext {
  public:
    WhereOPContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhereOPContext* whereOP();

  class  DropIndexQueryContext : public antlr4::ParserRuleContext {
  public:
    DropIndexQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *INDEX();
    IndexNameContext *indexName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DropIndexQueryContext* dropIndexQuery();

  class  DropTableQueryContext : public antlr4::ParserRuleContext {
  public:
    DropTableQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DROP();
    antlr4::tree::TerminalNode *TABLE();
    TableNameContext *tableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DropTableQueryContext* dropTableQuery();

  class  CreateIndexQueryContext : public antlr4::ParserRuleContext {
  public:
    CreateIndexQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *INDEX();
    IndexNameContext *indexName();
    antlr4::tree::TerminalNode *ON();
    TableNameContext *tableName();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    ColumnNameContext *columnName();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreateIndexQueryContext* createIndexQuery();

  class  CreateTableQueryContext : public antlr4::ParserRuleContext {
  public:
    CreateTableQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CREATE();
    antlr4::tree::TerminalNode *TABLE();
    TableNameContext *tableName();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    ColumnDefinitionsContext *columnDefinitions();
    PrimaryKeyDefinitionContext *primaryKeyDefinition();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CreateTableQueryContext* createTableQuery();

  class  ColumnDefinitionsContext : public antlr4::ParserRuleContext {
  public:
    ColumnDefinitionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ColumnDefinitionContext *> columnDefinition();
    ColumnDefinitionContext* columnDefinition(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnDefinitionsContext* columnDefinitions();

  class  ColumnDefinitionContext : public antlr4::ParserRuleContext {
  public:
    ColumnDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ColumnDefinitionContext() = default;
    void copyFrom(ColumnDefinitionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NonUniqueColumnDefinitionContext : public ColumnDefinitionContext {
  public:
    NonUniqueColumnDefinitionContext(ColumnDefinitionContext *ctx);

    ColumnNameContext *columnName();
    TypeContext *type();
    antlr4::tree::TerminalNode *COMMA();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UniqueColumnDefinitionContext : public ColumnDefinitionContext {
  public:
    UniqueColumnDefinitionContext(ColumnDefinitionContext *ctx);

    ColumnNameContext *columnName();
    TypeContext *type();
    antlr4::tree::TerminalNode *UNIQUE();
    antlr4::tree::TerminalNode *COMMA();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ColumnDefinitionContext* columnDefinition();

  class  PrimaryKeyDefinitionContext : public antlr4::ParserRuleContext {
  public:
    PrimaryKeyDefinitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRIMARY_KEY();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    ColumnNameContext *columnName();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrimaryKeyDefinitionContext* primaryKeyDefinition();

  class  InsertQueryContext : public antlr4::ParserRuleContext {
  public:
    InsertQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INSERT();
    antlr4::tree::TerminalNode *INTO();
    TableNameContext *tableName();
    antlr4::tree::TerminalNode *VALUES();
    LiteralValuesContext *literalValues();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InsertQueryContext* insertQuery();

  class  LiteralValuesContext : public antlr4::ParserRuleContext {
  public:
    LiteralValuesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    std::vector<LiteralContext *> literal();
    LiteralContext* literal(size_t i);
    antlr4::tree::TerminalNode *CLOSE_BRACKET();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralValuesContext* literalValues();

  class  DeleteQueryContext : public antlr4::ParserRuleContext {
  public:
    DeleteQueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DELETE();
    antlr4::tree::TerminalNode *FROM();
    TableNameContext *tableName();
    OptionalWhereClauseContext *optionalWhereClause();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeleteQueryContext* deleteQuery();

  class  QuitStatementContext : public antlr4::ParserRuleContext {
  public:
    QuitStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *QUIT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  QuitStatementContext* quitStatement();

  class  ExecfileStatementContext : public antlr4::ParserRuleContext {
  public:
    ExecfileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EXECFILE();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExecfileStatementContext* execfileStatement();

  class  TableNameContext : public antlr4::ParserRuleContext {
  public:
    TableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TableNameContext* tableName();

  class  ColumnNameContext : public antlr4::ParserRuleContext {
  public:
    ColumnNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ColumnNameContext* columnName();

  class  IndexNameContext : public antlr4::ParserRuleContext {
  public:
    IndexNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TOKEN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IndexNameContext* indexName();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DECIMAL_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *REAL_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralContext* literal();

  class  OpContext : public antlr4::ParserRuleContext {
  public:
    OpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    OpContext() = default;
    void copyFrom(OpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  OpGTEContext : public OpContext {
  public:
    OpGTEContext(OpContext *ctx);

    antlr4::tree::TerminalNode *GREATER_EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpEQContext : public OpContext {
  public:
    OpEQContext(OpContext *ctx);

    antlr4::tree::TerminalNode *EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpNEQContext : public OpContext {
  public:
    OpNEQContext(OpContext *ctx);

    antlr4::tree::TerminalNode *NOT_EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpGTContext : public OpContext {
  public:
    OpGTContext(OpContext *ctx);

    antlr4::tree::TerminalNode *GREATER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpLTEContext : public OpContext {
  public:
    OpLTEContext(OpContext *ctx);

    antlr4::tree::TerminalNode *SMALLER_EQUAL();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  OpLTContext : public OpContext {
  public:
    OpLTContext(OpContext *ctx);

    antlr4::tree::TerminalNode *SMALLER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  OpContext* op();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeContext() = default;
    void copyFrom(TypeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IntTypeDefContext : public TypeContext {
  public:
    IntTypeDefContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *INT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharTypeDefContext : public TypeContext {
  public:
    CharTypeDefContext(TypeContext *ctx);

    CharTypeContext *charType();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatTypeDefContext : public TypeContext {
  public:
    FloatTypeDefContext(TypeContext *ctx);

    antlr4::tree::TerminalNode *FLOAT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeContext* type();

  class  CharTypeContext : public antlr4::ParserRuleContext {
  public:
    CharTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *OPEN_BRACKET();
    antlr4::tree::TerminalNode *DECIMAL_LITERAL();
    antlr4::tree::TerminalNode *CLOSE_BRACKET();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharTypeContext* charType();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

