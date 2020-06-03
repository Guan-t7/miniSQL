
// Generated from sqlParser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "sqlParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by sqlParser.
 */
class  sqlParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by sqlParser.
   */
    virtual antlrcpp::Any visitRoot(sqlParser::RootContext *context) = 0;

    virtual antlrcpp::Any visitSqlStatements(sqlParser::SqlStatementsContext *context) = 0;

    virtual antlrcpp::Any visitSqlStatement(sqlParser::SqlStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(sqlParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectQuery(sqlParser::SelectQueryContext *context) = 0;

    virtual antlrcpp::Any visitSelectTarget(sqlParser::SelectTargetContext *context) = 0;

    virtual antlrcpp::Any visitOptionalWhereClause(sqlParser::OptionalWhereClauseContext *context) = 0;

    virtual antlrcpp::Any visitWhereClause(sqlParser::WhereClauseContext *context) = 0;

    virtual antlrcpp::Any visitWhereConditions(sqlParser::WhereConditionsContext *context) = 0;

    virtual antlrcpp::Any visitWhereCondition(sqlParser::WhereConditionContext *context) = 0;

    virtual antlrcpp::Any visitWhereOP(sqlParser::WhereOPContext *context) = 0;

    virtual antlrcpp::Any visitDropIndexQuery(sqlParser::DropIndexQueryContext *context) = 0;

    virtual antlrcpp::Any visitDropTableQuery(sqlParser::DropTableQueryContext *context) = 0;

    virtual antlrcpp::Any visitCreateIndexQuery(sqlParser::CreateIndexQueryContext *context) = 0;

    virtual antlrcpp::Any visitCreateTableQuery(sqlParser::CreateTableQueryContext *context) = 0;

    virtual antlrcpp::Any visitColumnDefinitions(sqlParser::ColumnDefinitionsContext *context) = 0;

    virtual antlrcpp::Any visitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitInsertQuery(sqlParser::InsertQueryContext *context) = 0;

    virtual antlrcpp::Any visitLiteralValues(sqlParser::LiteralValuesContext *context) = 0;

    virtual antlrcpp::Any visitDeleteQuery(sqlParser::DeleteQueryContext *context) = 0;

    virtual antlrcpp::Any visitQuitStatement(sqlParser::QuitStatementContext *context) = 0;

    virtual antlrcpp::Any visitExecfileStatement(sqlParser::ExecfileStatementContext *context) = 0;

    virtual antlrcpp::Any visitTableName(sqlParser::TableNameContext *context) = 0;

    virtual antlrcpp::Any visitColumnName(sqlParser::ColumnNameContext *context) = 0;

    virtual antlrcpp::Any visitIndexName(sqlParser::IndexNameContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(sqlParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitOpEQ(sqlParser::OpEQContext *context) = 0;

    virtual antlrcpp::Any visitOpNEQ(sqlParser::OpNEQContext *context) = 0;

    virtual antlrcpp::Any visitOpLT(sqlParser::OpLTContext *context) = 0;

    virtual antlrcpp::Any visitOpLTE(sqlParser::OpLTEContext *context) = 0;

    virtual antlrcpp::Any visitOpGT(sqlParser::OpGTContext *context) = 0;

    virtual antlrcpp::Any visitOpGTE(sqlParser::OpGTEContext *context) = 0;

    virtual antlrcpp::Any visitCharTypeDef(sqlParser::CharTypeDefContext *context) = 0;

    virtual antlrcpp::Any visitIntTypeDef(sqlParser::IntTypeDefContext *context) = 0;

    virtual antlrcpp::Any visitFloatTypeDef(sqlParser::FloatTypeDefContext *context) = 0;

    virtual antlrcpp::Any visitCharType(sqlParser::CharTypeContext *context) = 0;


};

