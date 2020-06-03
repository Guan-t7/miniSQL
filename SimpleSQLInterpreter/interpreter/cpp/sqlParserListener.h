
// Generated from sqlParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "sqlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by sqlParser.
 */
class  sqlParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRoot(sqlParser::RootContext *ctx) = 0;
  virtual void exitRoot(sqlParser::RootContext *ctx) = 0;

  virtual void enterSqlStatements(sqlParser::SqlStatementsContext *ctx) = 0;
  virtual void exitSqlStatements(sqlParser::SqlStatementsContext *ctx) = 0;

  virtual void enterSqlStatement(sqlParser::SqlStatementContext *ctx) = 0;
  virtual void exitSqlStatement(sqlParser::SqlStatementContext *ctx) = 0;

  virtual void enterEmptyStatement(sqlParser::EmptyStatementContext *ctx) = 0;
  virtual void exitEmptyStatement(sqlParser::EmptyStatementContext *ctx) = 0;

  virtual void enterSelectQuery(sqlParser::SelectQueryContext *ctx) = 0;
  virtual void exitSelectQuery(sqlParser::SelectQueryContext *ctx) = 0;

  virtual void enterSelectTarget(sqlParser::SelectTargetContext *ctx) = 0;
  virtual void exitSelectTarget(sqlParser::SelectTargetContext *ctx) = 0;

  virtual void enterOptionalWhereClause(sqlParser::OptionalWhereClauseContext *ctx) = 0;
  virtual void exitOptionalWhereClause(sqlParser::OptionalWhereClauseContext *ctx) = 0;

  virtual void enterWhereClause(sqlParser::WhereClauseContext *ctx) = 0;
  virtual void exitWhereClause(sqlParser::WhereClauseContext *ctx) = 0;

  virtual void enterWhereConditions(sqlParser::WhereConditionsContext *ctx) = 0;
  virtual void exitWhereConditions(sqlParser::WhereConditionsContext *ctx) = 0;

  virtual void enterWhereCondition(sqlParser::WhereConditionContext *ctx) = 0;
  virtual void exitWhereCondition(sqlParser::WhereConditionContext *ctx) = 0;

  virtual void enterWhereOP(sqlParser::WhereOPContext *ctx) = 0;
  virtual void exitWhereOP(sqlParser::WhereOPContext *ctx) = 0;

  virtual void enterDropIndexQuery(sqlParser::DropIndexQueryContext *ctx) = 0;
  virtual void exitDropIndexQuery(sqlParser::DropIndexQueryContext *ctx) = 0;

  virtual void enterDropTableQuery(sqlParser::DropTableQueryContext *ctx) = 0;
  virtual void exitDropTableQuery(sqlParser::DropTableQueryContext *ctx) = 0;

  virtual void enterCreateIndexQuery(sqlParser::CreateIndexQueryContext *ctx) = 0;
  virtual void exitCreateIndexQuery(sqlParser::CreateIndexQueryContext *ctx) = 0;

  virtual void enterCreateTableQuery(sqlParser::CreateTableQueryContext *ctx) = 0;
  virtual void exitCreateTableQuery(sqlParser::CreateTableQueryContext *ctx) = 0;

  virtual void enterColumnDefinitions(sqlParser::ColumnDefinitionsContext *ctx) = 0;
  virtual void exitColumnDefinitions(sqlParser::ColumnDefinitionsContext *ctx) = 0;

  virtual void enterNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext *ctx) = 0;
  virtual void exitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext *ctx) = 0;

  virtual void enterUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext *ctx) = 0;
  virtual void exitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext *ctx) = 0;

  virtual void enterPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext *ctx) = 0;
  virtual void exitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext *ctx) = 0;

  virtual void enterInsertQuery(sqlParser::InsertQueryContext *ctx) = 0;
  virtual void exitInsertQuery(sqlParser::InsertQueryContext *ctx) = 0;

  virtual void enterLiteralValues(sqlParser::LiteralValuesContext *ctx) = 0;
  virtual void exitLiteralValues(sqlParser::LiteralValuesContext *ctx) = 0;

  virtual void enterDeleteQuery(sqlParser::DeleteQueryContext *ctx) = 0;
  virtual void exitDeleteQuery(sqlParser::DeleteQueryContext *ctx) = 0;

  virtual void enterQuitStatement(sqlParser::QuitStatementContext *ctx) = 0;
  virtual void exitQuitStatement(sqlParser::QuitStatementContext *ctx) = 0;

  virtual void enterExecfileStatement(sqlParser::ExecfileStatementContext *ctx) = 0;
  virtual void exitExecfileStatement(sqlParser::ExecfileStatementContext *ctx) = 0;

  virtual void enterTableName(sqlParser::TableNameContext *ctx) = 0;
  virtual void exitTableName(sqlParser::TableNameContext *ctx) = 0;

  virtual void enterColumnName(sqlParser::ColumnNameContext *ctx) = 0;
  virtual void exitColumnName(sqlParser::ColumnNameContext *ctx) = 0;

  virtual void enterIndexName(sqlParser::IndexNameContext *ctx) = 0;
  virtual void exitIndexName(sqlParser::IndexNameContext *ctx) = 0;

  virtual void enterLiteral(sqlParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(sqlParser::LiteralContext *ctx) = 0;

  virtual void enterOpEQ(sqlParser::OpEQContext *ctx) = 0;
  virtual void exitOpEQ(sqlParser::OpEQContext *ctx) = 0;

  virtual void enterOpNEQ(sqlParser::OpNEQContext *ctx) = 0;
  virtual void exitOpNEQ(sqlParser::OpNEQContext *ctx) = 0;

  virtual void enterOpLT(sqlParser::OpLTContext *ctx) = 0;
  virtual void exitOpLT(sqlParser::OpLTContext *ctx) = 0;

  virtual void enterOpLTE(sqlParser::OpLTEContext *ctx) = 0;
  virtual void exitOpLTE(sqlParser::OpLTEContext *ctx) = 0;

  virtual void enterOpGT(sqlParser::OpGTContext *ctx) = 0;
  virtual void exitOpGT(sqlParser::OpGTContext *ctx) = 0;

  virtual void enterOpGTE(sqlParser::OpGTEContext *ctx) = 0;
  virtual void exitOpGTE(sqlParser::OpGTEContext *ctx) = 0;

  virtual void enterCharTypeDef(sqlParser::CharTypeDefContext *ctx) = 0;
  virtual void exitCharTypeDef(sqlParser::CharTypeDefContext *ctx) = 0;

  virtual void enterIntTypeDef(sqlParser::IntTypeDefContext *ctx) = 0;
  virtual void exitIntTypeDef(sqlParser::IntTypeDefContext *ctx) = 0;

  virtual void enterFloatTypeDef(sqlParser::FloatTypeDefContext *ctx) = 0;
  virtual void exitFloatTypeDef(sqlParser::FloatTypeDefContext *ctx) = 0;

  virtual void enterCharType(sqlParser::CharTypeContext *ctx) = 0;
  virtual void exitCharType(sqlParser::CharTypeContext *ctx) = 0;


};

