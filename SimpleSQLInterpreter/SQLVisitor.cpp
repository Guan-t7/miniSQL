#include "SQLVisitor.h"

antlrcpp::Any SQLVisitor::visitRoot(sqlParser::RootContext* ctx) {
	//int
	for (auto child : ctx->children) {
		auto result = child->accept(this);
		if (result.isNotNull()) {
			if (result.as<int>() != SUCCESS) return result;
		}
	}
	return SUCCESS;
}

antlrcpp::Any SQLVisitor::visitSqlStatements(sqlParser::SqlStatementsContext* ctx) {
	for (auto child : ctx->children) {
		auto result = child->accept(this);
		if (result.isNotNull()) {
			if (result.as<int>() != SUCCESS) return result;
		}
	}
	return SUCCESS;
}

antlrcpp::Any SQLVisitor::visitSqlStatement(sqlParser::SqlStatementContext* ctx) {
	for (auto child : ctx->children) {
		const int result = child->accept(this);
		if (result != SUCCESS) return result;
	}
	return SUCCESS;
}

antlrcpp::Any SQLVisitor::visitEmptyStatement(sqlParser::EmptyStatementContext* ctx) {
	return SUCCESS;
}

antlrcpp::Any SQLVisitor::visitSelectQuery(sqlParser::SelectQueryContext* ctx) {
	auto result = DBExecutor::selectQuery(ctx->selectTarget()->accept(this), ctx->optionalWhereClause()->accept(this));
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitSelectTarget(sqlParser::SelectTargetContext* ctx) {
	return ctx->tableName()->TOKEN()->getText();
}

antlrcpp::Any SQLVisitor::visitOptionalWhereClause(sqlParser::OptionalWhereClauseContext* ctx) {
	auto ret = visitChildren(ctx);
	if (ret.isNull()) return antlrcpp::Any(std::vector<Condition>());
	else return ret;
}

antlrcpp::Any SQLVisitor::visitWhereClause(sqlParser::WhereClauseContext* ctx) {
	return ctx->whereConditions()->accept(this);
}

antlrcpp::Any SQLVisitor::visitWhereConditions(sqlParser::WhereConditionsContext* ctx) {
	std::vector<Condition> conditions;
	for (auto condition : ctx->whereCondition()) {
		conditions.emplace_back(condition->accept(this));
	}
	return conditions;
}

antlrcpp::Any SQLVisitor::visitWhereCondition(sqlParser::WhereConditionContext* ctx) {
	Condition c(ctx->columnName()->accept(this), ctx->op()->accept(this), ctx->literal()->accept(this));
	return c;
}

antlrcpp::Any SQLVisitor::visitWhereOP(sqlParser::WhereOPContext* ctx) {
	return visitChildren(ctx);
}

antlrcpp::Any SQLVisitor::visitDropIndexQuery(sqlParser::DropIndexQueryContext* ctx) {
	auto result = DBExecutor::dropIndexQuery(ctx->indexName()->accept(this));
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitDropTableQuery(sqlParser::DropTableQueryContext* ctx) {
	auto result = DBExecutor::dropTableQuery(ctx->tableName()->accept(this));
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitCreateIndexQuery(sqlParser::CreateIndexQueryContext* ctx) {
	const IndexInfo info{
		ctx->tableName()->accept(this), ctx->indexName()->accept(this), ctx->columnName()->accept(this)
	};
	auto result = DBExecutor::createIndexQuery(info);
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitCreateTableQuery(sqlParser::CreateTableQueryContext* ctx) {
	std::string primaryKey;
	auto pk = ctx->primaryKeyDefinition()->accept(this);
	if (pk.isNotNull()) primaryKey = pk.as<std::string>();
	const TableInfo info{ ctx->tableName()->accept(this), ctx->columnDefinitions()->accept(this), primaryKey };

	auto result = DBExecutor::createTableQuery(info);
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitColumnDefinitions(sqlParser::ColumnDefinitionsContext* ctx) {
	std::vector<Column> columns;
	for (auto* column : ctx->columnDefinition()) {
		columns.emplace_back(column->accept(this).as<Column>());
	}
	return columns;
}

antlrcpp::Any SQLVisitor::visitUniqueColumnDefinition(sqlParser::UniqueColumnDefinitionContext* ctx) {
	std::pair<std::string, int> type = ctx->type()->accept(this);
	return Column{ ctx->columnName()->accept(this), type, true };
}

antlrcpp::Any SQLVisitor::visitNonUniqueColumnDefinition(sqlParser::NonUniqueColumnDefinitionContext* ctx) {
	std::pair<std::string, int> type = ctx->type()->accept(this);
	return Column{ ctx->columnName()->accept(this), type , false };
}

antlrcpp::Any SQLVisitor::visitPrimaryKeyDefinition(sqlParser::PrimaryKeyDefinitionContext* ctx) {
	return ctx->columnName()->TOKEN()->getText();
}

antlrcpp::Any SQLVisitor::visitInsertQuery(sqlParser::InsertQueryContext* ctx) {
	std::string tableName = ctx->tableName()->accept(this);
	auto result = DBExecutor::insertQuery(tableName, ctx->literalValues()->accept(this));
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitLiteralValues(sqlParser::LiteralValuesContext* ctx) {
	std::vector<std::string> values;
	for (auto child : ctx->children) {
		auto result = child->accept(this);
		if (result.isNotNull()) {
			values.emplace_back(result.as<std::string>());
		}
	}
	return values;
}

antlrcpp::Any SQLVisitor::visitDeleteQuery(sqlParser::DeleteQueryContext* ctx) {
	auto result = DBExecutor::deleteQuery(ctx->tableName()->accept(this), ctx->optionalWhereClause()->accept(this));
	std::cout << result.print();
	return result.getStatus();
}

antlrcpp::Any SQLVisitor::visitQuitStatement(sqlParser::QuitStatementContext* ctx) {
	return EXIT;
}

antlrcpp::Any SQLVisitor::visitExecfileStatement(sqlParser::ExecfileStatementContext* ctx) {
	std::string s = ctx->STRING_LITERAL()->getText();
	if (s.size() > 2 && s[0] == '"') //A string 
		s = s.substr(1, s.size() - 2);
	return Interpreter::execfileStatement(s);
}

antlrcpp::Any SQLVisitor::visitTableName(sqlParser::TableNameContext* ctx) {
	return ctx->TOKEN()->getText();
}

antlrcpp::Any SQLVisitor::visitColumnName(sqlParser::ColumnNameContext* ctx) {
	return ctx->TOKEN()->getText();
}

antlrcpp::Any SQLVisitor::visitIndexName(sqlParser::IndexNameContext* ctx) {
	return ctx->TOKEN()->getText();
}

antlrcpp::Any SQLVisitor::visitLiteral(sqlParser::LiteralContext* ctx) {
	std::string s = ctx->getText();
	if (s.size() > 2 && s[0] == '"') //A string 
		s = s.substr(1, s.size() - 2);
	return s;
}

antlrcpp::Any SQLVisitor::visitOpEQ(sqlParser::OpEQContext* ctx) {
	return opType::E;
}

antlrcpp::Any SQLVisitor::visitOpNEQ(sqlParser::OpNEQContext* ctx) {
	return opType::NE;
}

antlrcpp::Any SQLVisitor::visitOpLT(sqlParser::OpLTContext* ctx) {
	return opType::L;
}

antlrcpp::Any SQLVisitor::visitOpLTE(sqlParser::OpLTEContext* ctx) {
	return opType::LE;
}

antlrcpp::Any SQLVisitor::visitOpGT(sqlParser::OpGTContext* ctx) {
	return opType::G;
}

antlrcpp::Any SQLVisitor::visitOpGTE(sqlParser::OpGTEContext* ctx) {
	return opType::GE;
}

antlrcpp::Any SQLVisitor::visitCharTypeDef(sqlParser::CharTypeDefContext* ctx) {
	return ctx->charType()->accept(this);
}

antlrcpp::Any SQLVisitor::visitIntTypeDef(sqlParser::IntTypeDefContext* ctx) {
	return std::make_pair(std::string("int"), 0);
}

antlrcpp::Any SQLVisitor::visitFloatTypeDef(sqlParser::FloatTypeDefContext* ctx) {
	return std::make_pair(std::string("float"), 0);
}

antlrcpp::Any SQLVisitor::visitCharType(sqlParser::CharTypeContext* ctx) {
	return std::make_pair(std::string("char"), std::stoi(ctx->DECIMAL_LITERAL()->getText()));
}
