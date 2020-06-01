
// Generated from sqlParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "sqlParserVisitor.h"


/**
 * This class provides an empty implementation of sqlParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  sqlParserBaseVisitor : public sqlParserVisitor {
public:

  virtual antlrcpp::Any visitRoot(sqlParser::RootContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatements(sqlParser::SqlStatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSqlStatement(sqlParser::SqlStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(sqlParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectQuery(sqlParser::SelectQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelectTarget(sqlParser::SelectTargetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOptionalWhereClause(sqlParser::OptionalWhereClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhereClause(sqlParser::WhereClauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhereConditions(sqlParser::WhereConditionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhereCondition(sqlParser::WhereConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhereOP(sqlParser::WhereOPContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropIndexQuery(sqlParser::DropIndexQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDropTableQuery(sqlParser::DropTableQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateIndexQuery(sqlParser::CreateIndexQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCreateTableQuery(sqlParser::CreateTableQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnDefinitions(sqlParser::ColumnDefinitionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInsertQuery(sqlParser::InsertQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralValues(sqlParser::LiteralValuesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeleteQuery(sqlParser::DeleteQueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitQuitStatement(sqlParser::QuitStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExecfileStatement(sqlParser::ExecfileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTableName(sqlParser::TableNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumnName(sqlParser::ColumnNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndexName(sqlParser::IndexNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(sqlParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOp(sqlParser::OpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharTypeDef(sqlParser::CharTypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntTypeDef(sqlParser::IntTypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatTypeDef(sqlParser::FloatTypeDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharType(sqlParser::CharTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

