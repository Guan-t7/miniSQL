// Generated from sqlParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link sqlParser}.
 */
public interface sqlParserListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link sqlParser#root}.
	 * @param ctx the parse tree
	 */
	void enterRoot(sqlParser.RootContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#root}.
	 * @param ctx the parse tree
	 */
	void exitRoot(sqlParser.RootContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#sqlStatements}.
	 * @param ctx the parse tree
	 */
	void enterSqlStatements(sqlParser.SqlStatementsContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#sqlStatements}.
	 * @param ctx the parse tree
	 */
	void exitSqlStatements(sqlParser.SqlStatementsContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#sqlStatement}.
	 * @param ctx the parse tree
	 */
	void enterSqlStatement(sqlParser.SqlStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#sqlStatement}.
	 * @param ctx the parse tree
	 */
	void exitSqlStatement(sqlParser.SqlStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#emptyStatement}.
	 * @param ctx the parse tree
	 */
	void enterEmptyStatement(sqlParser.EmptyStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#emptyStatement}.
	 * @param ctx the parse tree
	 */
	void exitEmptyStatement(sqlParser.EmptyStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#selectQuery}.
	 * @param ctx the parse tree
	 */
	void enterSelectQuery(sqlParser.SelectQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#selectQuery}.
	 * @param ctx the parse tree
	 */
	void exitSelectQuery(sqlParser.SelectQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#selectTarget}.
	 * @param ctx the parse tree
	 */
	void enterSelectTarget(sqlParser.SelectTargetContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#selectTarget}.
	 * @param ctx the parse tree
	 */
	void exitSelectTarget(sqlParser.SelectTargetContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#optionalWhereClause}.
	 * @param ctx the parse tree
	 */
	void enterOptionalWhereClause(sqlParser.OptionalWhereClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#optionalWhereClause}.
	 * @param ctx the parse tree
	 */
	void exitOptionalWhereClause(sqlParser.OptionalWhereClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#whereClause}.
	 * @param ctx the parse tree
	 */
	void enterWhereClause(sqlParser.WhereClauseContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#whereClause}.
	 * @param ctx the parse tree
	 */
	void exitWhereClause(sqlParser.WhereClauseContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#whereConditions}.
	 * @param ctx the parse tree
	 */
	void enterWhereConditions(sqlParser.WhereConditionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#whereConditions}.
	 * @param ctx the parse tree
	 */
	void exitWhereConditions(sqlParser.WhereConditionsContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#whereCondition}.
	 * @param ctx the parse tree
	 */
	void enterWhereCondition(sqlParser.WhereConditionContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#whereCondition}.
	 * @param ctx the parse tree
	 */
	void exitWhereCondition(sqlParser.WhereConditionContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#whereOP}.
	 * @param ctx the parse tree
	 */
	void enterWhereOP(sqlParser.WhereOPContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#whereOP}.
	 * @param ctx the parse tree
	 */
	void exitWhereOP(sqlParser.WhereOPContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#dropIndexQuery}.
	 * @param ctx the parse tree
	 */
	void enterDropIndexQuery(sqlParser.DropIndexQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#dropIndexQuery}.
	 * @param ctx the parse tree
	 */
	void exitDropIndexQuery(sqlParser.DropIndexQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#dropTableQuery}.
	 * @param ctx the parse tree
	 */
	void enterDropTableQuery(sqlParser.DropTableQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#dropTableQuery}.
	 * @param ctx the parse tree
	 */
	void exitDropTableQuery(sqlParser.DropTableQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#createIndexQuery}.
	 * @param ctx the parse tree
	 */
	void enterCreateIndexQuery(sqlParser.CreateIndexQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#createIndexQuery}.
	 * @param ctx the parse tree
	 */
	void exitCreateIndexQuery(sqlParser.CreateIndexQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#createTableQuery}.
	 * @param ctx the parse tree
	 */
	void enterCreateTableQuery(sqlParser.CreateTableQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#createTableQuery}.
	 * @param ctx the parse tree
	 */
	void exitCreateTableQuery(sqlParser.CreateTableQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#columnDefinitions}.
	 * @param ctx the parse tree
	 */
	void enterColumnDefinitions(sqlParser.ColumnDefinitionsContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#columnDefinitions}.
	 * @param ctx the parse tree
	 */
	void exitColumnDefinitions(sqlParser.ColumnDefinitionsContext ctx);
	/**
	 * Enter a parse tree produced by the {@code nonUniqueColumnDefinition}
	 * labeled alternative in {@link sqlParser#columnDefinition}.
	 * @param ctx the parse tree
	 */
	void enterNonUniqueColumnDefinition(sqlParser.NonUniqueColumnDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code nonUniqueColumnDefinition}
	 * labeled alternative in {@link sqlParser#columnDefinition}.
	 * @param ctx the parse tree
	 */
	void exitNonUniqueColumnDefinition(sqlParser.NonUniqueColumnDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by the {@code uniqueColumnDefinition}
	 * labeled alternative in {@link sqlParser#columnDefinition}.
	 * @param ctx the parse tree
	 */
	void enterUniqueColumnDefinition(sqlParser.UniqueColumnDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by the {@code uniqueColumnDefinition}
	 * labeled alternative in {@link sqlParser#columnDefinition}.
	 * @param ctx the parse tree
	 */
	void exitUniqueColumnDefinition(sqlParser.UniqueColumnDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#primaryKeyDefinition}.
	 * @param ctx the parse tree
	 */
	void enterPrimaryKeyDefinition(sqlParser.PrimaryKeyDefinitionContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#primaryKeyDefinition}.
	 * @param ctx the parse tree
	 */
	void exitPrimaryKeyDefinition(sqlParser.PrimaryKeyDefinitionContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#insertQuery}.
	 * @param ctx the parse tree
	 */
	void enterInsertQuery(sqlParser.InsertQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#insertQuery}.
	 * @param ctx the parse tree
	 */
	void exitInsertQuery(sqlParser.InsertQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#literalValues}.
	 * @param ctx the parse tree
	 */
	void enterLiteralValues(sqlParser.LiteralValuesContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#literalValues}.
	 * @param ctx the parse tree
	 */
	void exitLiteralValues(sqlParser.LiteralValuesContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#deleteQuery}.
	 * @param ctx the parse tree
	 */
	void enterDeleteQuery(sqlParser.DeleteQueryContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#deleteQuery}.
	 * @param ctx the parse tree
	 */
	void exitDeleteQuery(sqlParser.DeleteQueryContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#quitStatement}.
	 * @param ctx the parse tree
	 */
	void enterQuitStatement(sqlParser.QuitStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#quitStatement}.
	 * @param ctx the parse tree
	 */
	void exitQuitStatement(sqlParser.QuitStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#execfileStatement}.
	 * @param ctx the parse tree
	 */
	void enterExecfileStatement(sqlParser.ExecfileStatementContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#execfileStatement}.
	 * @param ctx the parse tree
	 */
	void exitExecfileStatement(sqlParser.ExecfileStatementContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#tableName}.
	 * @param ctx the parse tree
	 */
	void enterTableName(sqlParser.TableNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#tableName}.
	 * @param ctx the parse tree
	 */
	void exitTableName(sqlParser.TableNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#columnName}.
	 * @param ctx the parse tree
	 */
	void enterColumnName(sqlParser.ColumnNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#columnName}.
	 * @param ctx the parse tree
	 */
	void exitColumnName(sqlParser.ColumnNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#indexName}.
	 * @param ctx the parse tree
	 */
	void enterIndexName(sqlParser.IndexNameContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#indexName}.
	 * @param ctx the parse tree
	 */
	void exitIndexName(sqlParser.IndexNameContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#literal}.
	 * @param ctx the parse tree
	 */
	void enterLiteral(sqlParser.LiteralContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#literal}.
	 * @param ctx the parse tree
	 */
	void exitLiteral(sqlParser.LiteralContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#op}.
	 * @param ctx the parse tree
	 */
	void enterOp(sqlParser.OpContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#op}.
	 * @param ctx the parse tree
	 */
	void exitOp(sqlParser.OpContext ctx);
	/**
	 * Enter a parse tree produced by the {@code charTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void enterCharTypeDef(sqlParser.CharTypeDefContext ctx);
	/**
	 * Exit a parse tree produced by the {@code charTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void exitCharTypeDef(sqlParser.CharTypeDefContext ctx);
	/**
	 * Enter a parse tree produced by the {@code intTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void enterIntTypeDef(sqlParser.IntTypeDefContext ctx);
	/**
	 * Exit a parse tree produced by the {@code intTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void exitIntTypeDef(sqlParser.IntTypeDefContext ctx);
	/**
	 * Enter a parse tree produced by the {@code floatTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void enterFloatTypeDef(sqlParser.FloatTypeDefContext ctx);
	/**
	 * Exit a parse tree produced by the {@code floatTypeDef}
	 * labeled alternative in {@link sqlParser#type}.
	 * @param ctx the parse tree
	 */
	void exitFloatTypeDef(sqlParser.FloatTypeDefContext ctx);
	/**
	 * Enter a parse tree produced by {@link sqlParser#charType}.
	 * @param ctx the parse tree
	 */
	void enterCharType(sqlParser.CharTypeContext ctx);
	/**
	 * Exit a parse tree produced by {@link sqlParser#charType}.
	 * @param ctx the parse tree
	 */
	void exitCharType(sqlParser.CharTypeContext ctx);
}