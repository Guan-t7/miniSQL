
// Generated from sqlParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "sqlParserListener.h"


/**
 * This class provides an empty implementation of sqlParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  sqlParserBaseListener : public sqlParserListener {
public:

  virtual void enterRoot(sqlParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(sqlParser::RootContext * /*ctx*/) override { }

  virtual void enterSqlStatements(sqlParser::SqlStatementsContext * /*ctx*/) override { }
  virtual void exitSqlStatements(sqlParser::SqlStatementsContext * /*ctx*/) override { }

  virtual void enterSqlStatement(sqlParser::SqlStatementContext * /*ctx*/) override { }
  virtual void exitSqlStatement(sqlParser::SqlStatementContext * /*ctx*/) override { }

  virtual void enterEmptyStatement(sqlParser::EmptyStatementContext * /*ctx*/) override { }
  virtual void exitEmptyStatement(sqlParser::EmptyStatementContext * /*ctx*/) override { }

  virtual void enterSelectQuery(sqlParser::SelectQueryContext * /*ctx*/) override { }
  virtual void exitSelectQuery(sqlParser::SelectQueryContext * /*ctx*/) override { }

  virtual void enterSelectTarget(sqlParser::SelectTargetContext * /*ctx*/) override { }
  virtual void exitSelectTarget(sqlParser::SelectTargetContext * /*ctx*/) override { }

  virtual void enterOptionalWhereClause(sqlParser::OptionalWhereClauseContext * /*ctx*/) override { }
  virtual void exitOptionalWhereClause(sqlParser::OptionalWhereClauseContext * /*ctx*/) override { }

  virtual void enterWhereClause(sqlParser::WhereClauseContext * /*ctx*/) override { }
  virtual void exitWhereClause(sqlParser::WhereClauseContext * /*ctx*/) override { }

  virtual void enterWhereConditions(sqlParser::WhereConditionsContext * /*ctx*/) override { }
  virtual void exitWhereConditions(sqlParser::WhereConditionsContext * /*ctx*/) override { }

  virtual void enterWhereCondition(sqlParser::WhereConditionContext * /*ctx*/) override { }
  virtual void exitWhereCondition(sqlParser::WhereConditionContext * /*ctx*/) override { }

  virtual void enterWhereOP(sqlParser::WhereOPContext * /*ctx*/) override { }
  virtual void exitWhereOP(sqlParser::WhereOPContext * /*ctx*/) override { }

  virtual void enterDropIndexQuery(sqlParser::DropIndexQueryContext * /*ctx*/) override { }
  virtual void exitDropIndexQuery(sqlParser::DropIndexQueryContext * /*ctx*/) override { }

  virtual void enterDropTableQuery(sqlParser::DropTableQueryContext * /*ctx*/) override { }
  virtual void exitDropTableQuery(sqlParser::DropTableQueryContext * /*ctx*/) override { }

  virtual void enterCreateIndexQuery(sqlParser::CreateIndexQueryContext * /*ctx*/) override { }
  virtual void exitCreateIndexQuery(sqlParser::CreateIndexQueryContext * /*ctx*/) override { }

  virtual void enterCreateTableQuery(sqlParser::CreateTableQueryContext * /*ctx*/) override { }
  virtual void exitCreateTableQuery(sqlParser::CreateTableQueryContext * /*ctx*/) override { }

  virtual void enterColumnDefinitions(sqlParser::ColumnDefinitionsContext * /*ctx*/) override { }
  virtual void exitColumnDefinitions(sqlParser::ColumnDefinitionsContext * /*ctx*/) override { }

  virtual void enterNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext * /*ctx*/) override { }
  virtual void exitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext * /*ctx*/) override { }

  virtual void enterUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext * /*ctx*/) override { }
  virtual void exitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext * /*ctx*/) override { }

  virtual void enterPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext * /*ctx*/) override { }
  virtual void exitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext * /*ctx*/) override { }

  virtual void enterInsertQuery(sqlParser::InsertQueryContext * /*ctx*/) override { }
  virtual void exitInsertQuery(sqlParser::InsertQueryContext * /*ctx*/) override { }

  virtual void enterLiteralValues(sqlParser::LiteralValuesContext * /*ctx*/) override { }
  virtual void exitLiteralValues(sqlParser::LiteralValuesContext * /*ctx*/) override { }

  virtual void enterDeleteQuery(sqlParser::DeleteQueryContext * /*ctx*/) override { }
  virtual void exitDeleteQuery(sqlParser::DeleteQueryContext * /*ctx*/) override { }

  virtual void enterQuitStatement(sqlParser::QuitStatementContext * /*ctx*/) override { }
  virtual void exitQuitStatement(sqlParser::QuitStatementContext * /*ctx*/) override { }

  virtual void enterExecfileStatement(sqlParser::ExecfileStatementContext * /*ctx*/) override { }
  virtual void exitExecfileStatement(sqlParser::ExecfileStatementContext * /*ctx*/) override { }

  virtual void enterTableName(sqlParser::TableNameContext * /*ctx*/) override { }
  virtual void exitTableName(sqlParser::TableNameContext * /*ctx*/) override { }

  virtual void enterColumnName(sqlParser::ColumnNameContext * /*ctx*/) override { }
  virtual void exitColumnName(sqlParser::ColumnNameContext * /*ctx*/) override { }

  virtual void enterIndexName(sqlParser::IndexNameContext * /*ctx*/) override { }
  virtual void exitIndexName(sqlParser::IndexNameContext * /*ctx*/) override { }

  virtual void enterLiteral(sqlParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(sqlParser::LiteralContext * /*ctx*/) override { }

  virtual void enterOp(sqlParser::OpContext * /*ctx*/) override { }
  virtual void exitOp(sqlParser::OpContext * /*ctx*/) override { }

  virtual void enterCharTypeDef(sqlParser::CharTypeDefContext * /*ctx*/) override { }
  virtual void exitCharTypeDef(sqlParser::CharTypeDefContext * /*ctx*/) override { }

  virtual void enterIntTypeDef(sqlParser::IntTypeDefContext * /*ctx*/) override { }
  virtual void exitIntTypeDef(sqlParser::IntTypeDefContext * /*ctx*/) override { }

  virtual void enterFloatTypeDef(sqlParser::FloatTypeDefContext * /*ctx*/) override { }
  virtual void exitFloatTypeDef(sqlParser::FloatTypeDefContext * /*ctx*/) override { }

  virtual void enterCharType(sqlParser::CharTypeContext * /*ctx*/) override { }
  virtual void exitCharType(sqlParser::CharTypeContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

