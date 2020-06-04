parser grammar sqlParser;
options {
	tokenVocab = sqlLexer;
	language = Cpp;
}

root: sqlStatements? EOF;

sqlStatements: (sqlStatement SEMICOLON | emptyStatement)* (
		sqlStatement (SEMICOLON)
		| emptyStatement
	);

sqlStatement:
	selectQuery
	| dropIndexQuery
	| dropTableQuery
	| createIndexQuery
	| createTableQuery
	| insertQuery
	| deleteQuery
	| quitStatement
	| execfileStatement;

emptyStatement: SEMICOLON;

//select
selectQuery:
	SELECT WILDCARD FROM selectTarget optionalWhereClause;

selectTarget: tableName;
//where
optionalWhereClause: whereClause |;
whereClause: WHERE whereConditions;
whereConditions: whereCondition (whereOP whereCondition)*;
whereCondition: columnName op literal;
whereOP: AND;

//drop
dropIndexQuery: DROP INDEX indexName;
dropTableQuery: DROP TABLE tableName;

//create
createIndexQuery:
	CREATE INDEX indexName ON tableName OPEN_BRACKET columnName CLOSE_BRACKET;

createTableQuery:
	CREATE TABLE tableName OPEN_BRACKET columnDefinitions primaryKeyDefinition CLOSE_BRACKET;

columnDefinitions: columnDefinition+;

columnDefinition:
	columnName type COMMA #nonUniqueColumnDefinition
	| columnName type UNIQUE COMMA #uniqueColumnDefinition;

primaryKeyDefinition:
	PRIMARY_KEY OPEN_BRACKET columnName CLOSE_BRACKET;

//insert
insertQuery: INSERT INTO tableName VALUES literalValues;

literalValues:
	OPEN_BRACKET literal (COMMA literal)* CLOSE_BRACKET;

//delete
deleteQuery: DELETE FROM tableName optionalWhereClause;

//misc

quitStatement: QUIT;
execfileStatement: EXECFILE STRING_LITERAL;

//basic
tableName: TOKEN;
columnName: TOKEN;
indexName: TOKEN;
literal: DECIMAL_LITERAL | STRING_LITERAL | REAL_LITERAL;
op:
	EQUAL #opEQ
	| NOT_EQUAL #opNEQ
	| SMALLER #opLT
	| SMALLER_EQUAL #opLTE
	| GREATER #opGT
	| GREATER_EQUAL #opGTE;
type:
	charType	# charTypeDef
	| INT		# intTypeDef
	| FLOAT		# floatTypeDef;

charType:
	CHAR OPEN_BRACKET DECIMAL_LITERAL CLOSE_BRACKET; //char(10)
