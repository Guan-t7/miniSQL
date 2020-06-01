#pragma once
#include "DBExecutor.h"
#include "error.h"
#include "Interpreter.h"
#include "SelectResult.h"
#include "interpreter/cpp/sqlParserVisitor.h"

class SQLVisitor :public sqlParserVisitor {
public:
	antlrcpp::Any visitRoot(sqlParser::RootContext* ctx) override;

	antlrcpp::Any visitSqlStatements(sqlParser::SqlStatementsContext* ctx) override;

	antlrcpp::Any visitSqlStatement(sqlParser::SqlStatementContext* ctx) override;

	antlrcpp::Any visitEmptyStatement(sqlParser::EmptyStatementContext* ctx) override;

	antlrcpp::Any visitSelectQuery(sqlParser::SelectQueryContext* ctx) override;

	//return table name
	antlrcpp::Any visitSelectTarget(sqlParser::SelectTargetContext* ctx) override;

	//return null or where conditions
	antlrcpp::Any visitOptionalWhereClause(sqlParser::OptionalWhereClauseContext* ctx) override;

	antlrcpp::Any visitWhereClause(sqlParser::WhereClauseContext* ctx) override;

	antlrcpp::Any visitWhereConditions(sqlParser::WhereConditionsContext* ctx) override;

	antlrcpp::Any visitWhereCondition(sqlParser::WhereConditionContext* ctx) override;

	//currently useless, just and and and
	antlrcpp::Any visitWhereOP(sqlParser::WhereOPContext* ctx) override;

	antlrcpp::Any visitDropIndexQuery(sqlParser::DropIndexQueryContext* ctx) override;

	antlrcpp::Any visitDropTableQuery(sqlParser::DropTableQueryContext* ctx) override;

	antlrcpp::Any visitCreateIndexQuery(sqlParser::CreateIndexQueryContext* ctx) override;

	antlrcpp::Any visitCreateTableQuery(sqlParser::CreateTableQueryContext* ctx) override;

	antlrcpp::Any visitColumnDefinitions(sqlParser::ColumnDefinitionsContext* ctx) override;

	antlrcpp::Any visitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext* ctx) override;

	antlrcpp::Any visitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext* ctx) override;

	antlrcpp::Any visitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext* ctx) override;

	antlrcpp::Any visitInsertQuery(sqlParser::InsertQueryContext* ctx) override;

	antlrcpp::Any visitLiteralValues(sqlParser::LiteralValuesContext* ctx) override;

	antlrcpp::Any visitDeleteQuery(sqlParser::DeleteQueryContext* ctx) override;

	antlrcpp::Any visitQuitStatement(sqlParser::QuitStatementContext* ctx) override;

	antlrcpp::Any visitExecfileStatement(sqlParser::ExecfileStatementContext* ctx) override;

	antlrcpp::Any visitTableName(sqlParser::TableNameContext* ctx) override;

	antlrcpp::Any visitColumnName(sqlParser::ColumnNameContext* ctx) override;

	antlrcpp::Any visitIndexName(sqlParser::IndexNameContext* ctx) override;

	antlrcpp::Any visitLiteral(sqlParser::LiteralContext* ctx) override;

	antlrcpp::Any visitOp(sqlParser::OpContext* ctx) override;

	antlrcpp::Any visitCharTypeDef(sqlParser::CharTypeDefContext* ctx) override;;

	antlrcpp::Any visitIntTypeDef(sqlParser::IntTypeDefContext* ctx) override;

	antlrcpp::Any visitFloatTypeDef(sqlParser::FloatTypeDefContext* ctx) override;

	antlrcpp::Any visitCharType(sqlParser::CharTypeContext* ctx) override;
};

