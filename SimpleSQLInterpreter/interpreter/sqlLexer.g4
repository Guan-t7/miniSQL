lexer grammar sqlLexer;
options {
	language = Cpp;
}
channels {
	ERRORCHANNEL,
	MYSQLCOMMENT
}

SPACE: [ \t\r\n]+ -> channel(HIDDEN);
SPEC_MYSQL_COMMENT: '/*!' .+? '*/' -> channel(MYSQLCOMMENT);
COMMENT_INPUT: '/*' .*? '*/' -> channel(HIDDEN);
LINE_COMMENT: (
		('-- ' | '#') ~[\r\n]* ('\r'? '\n' | EOF)
		| '--' ('\r'? '\n' | EOF)
	) -> channel(HIDDEN);

// query type
SELECT: 'select';
INSERT: 'insert';
DELETE: 'delete';
DROP: 'drop';
CREATE: 'create';
QUIT: 'quit';
EXECFILE: 'execfile';

//target
TABLE: 'table';
INDEX: 'index';
WILDCARD: '*';

//preposition
FROM: 'from';
INTO: 'into';
ON: 'on';
QUOTE: '\'' | '"';
OPEN_BRACKET: '(';
CLOSE_BRACKET: ')';

//contidion
WHERE: 'where';
EQUAL: '=';
NOT_EQUAL: '<>';
SMALLER: '<';
GREATER: '>';
SMALLER_EQUAL: '<=';
GREATER_EQUAL: '>=';
AND: 'and';
OR: 'or';

//type
CHAR: 'char';
INT: 'int';
FLOAT: 'float';

//attribute
UNIQUE: 'unique';

//literal
DECIMAL_LITERAL: [+-]? DEC_DIGIT+;
STRING_LITERAL: DQUOTA_STRING;
REAL_LITERAL:
	[+-]? (DEC_DIGIT+)? '.' DEC_DIGIT+
	| [+-]? DEC_DIGIT+ '.' EXPONENT_NUM_PART
	| [+-]? (DEC_DIGIT+)? '.' (DEC_DIGIT+ EXPONENT_NUM_PART)
	| [+-]? DEC_DIGIT+ EXPONENT_NUM_PART;
//misc
PRIMARY_KEY: 'primary key';
VALUES: 'values';
COMMA: ',';
SEMICOLON: ';';
//token

fragment EXPONENT_NUM_PART: 'E' [-+]? DEC_DIGIT+;
DQUOTA_STRING: '"' .*? '"';

fragment DEC_DIGIT: [0-9];

TOKEN: COLUMN_NAME | TABLE_NAME | INDEX_NAME;
fragment COLUMN_NAME: [A-Za-z]+ [A-Za-z0-9]*;
fragment TABLE_NAME: [A-Za-z]+ [A-Za-z0-9]*;
fragment INDEX_NAME: [A-Za-z]+ [A-Za-z0-9]*;

ERROR_RECONGNIGION: . -> channel(ERRORCHANNEL);