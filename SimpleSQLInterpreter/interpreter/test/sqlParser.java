// Generated from sqlParser.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class sqlParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		SPACE=1, SPEC_MYSQL_COMMENT=2, COMMENT_INPUT=3, LINE_COMMENT=4, SELECT=5, 
		INSERT=6, DELETE=7, DROP=8, CREATE=9, QUIT=10, EXECFILE=11, TABLE=12, 
		INDEX=13, WILDCARD=14, FROM=15, INTO=16, ON=17, QUOTE=18, OPEN_BRACKET=19, 
		CLOSE_BRACKET=20, WHERE=21, EQUAL=22, NOT_EQUAL=23, SMALLER=24, GREATER=25, 
		SMALLER_EQUAL=26, GREATER_EQUAL=27, AND=28, OR=29, CHAR=30, INT=31, FLOAT=32, 
		UNIQUE=33, DECIMAL_LITERAL=34, STRING_LITERAL=35, REAL_LITERAL=36, PRIMARY_KEY=37, 
		VALUES=38, COMMA=39, SEMICOLON=40, DQUOTA_STRING=41, TOKEN=42, ERROR_RECONGNIGION=43;
	public static final int
		RULE_root = 0, RULE_sqlStatements = 1, RULE_sqlStatement = 2, RULE_emptyStatement = 3, 
		RULE_selectQuery = 4, RULE_selectTarget = 5, RULE_optionalWhereClause = 6, 
		RULE_whereClause = 7, RULE_whereConditions = 8, RULE_whereCondition = 9, 
		RULE_whereOP = 10, RULE_dropIndexQuery = 11, RULE_dropTableQuery = 12, 
		RULE_createIndexQuery = 13, RULE_createTableQuery = 14, RULE_columnDefinitions = 15, 
		RULE_columnDefinition = 16, RULE_primaryKeyDefinition = 17, RULE_insertQuery = 18, 
		RULE_literalValues = 19, RULE_deleteQuery = 20, RULE_quitStatement = 21, 
		RULE_execfileStatement = 22, RULE_tableName = 23, RULE_columnName = 24, 
		RULE_indexName = 25, RULE_literal = 26, RULE_op = 27, RULE_type = 28, 
		RULE_charType = 29;
	private static String[] makeRuleNames() {
		return new String[] {
			"root", "sqlStatements", "sqlStatement", "emptyStatement", "selectQuery", 
			"selectTarget", "optionalWhereClause", "whereClause", "whereConditions", 
			"whereCondition", "whereOP", "dropIndexQuery", "dropTableQuery", "createIndexQuery", 
			"createTableQuery", "columnDefinitions", "columnDefinition", "primaryKeyDefinition", 
			"insertQuery", "literalValues", "deleteQuery", "quitStatement", "execfileStatement", 
			"tableName", "columnName", "indexName", "literal", "op", "type", "charType"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, null, "'select'", "'insert'", "'delete'", "'drop'", 
			"'create'", "'quit'", "'execfile'", "'table'", "'index'", "'*'", "'from'", 
			"'into'", "'on'", null, "'('", "')'", "'where'", "'='", "'<>'", "'<'", 
			"'>'", "'<='", "'>='", "'and'", "'or'", "'char'", "'int'", "'float'", 
			"'unique'", null, null, null, "'primary key'", "'values'", "','", "';'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "SPACE", "SPEC_MYSQL_COMMENT", "COMMENT_INPUT", "LINE_COMMENT", 
			"SELECT", "INSERT", "DELETE", "DROP", "CREATE", "QUIT", "EXECFILE", "TABLE", 
			"INDEX", "WILDCARD", "FROM", "INTO", "ON", "QUOTE", "OPEN_BRACKET", "CLOSE_BRACKET", 
			"WHERE", "EQUAL", "NOT_EQUAL", "SMALLER", "GREATER", "SMALLER_EQUAL", 
			"GREATER_EQUAL", "AND", "OR", "CHAR", "INT", "FLOAT", "UNIQUE", "DECIMAL_LITERAL", 
			"STRING_LITERAL", "REAL_LITERAL", "PRIMARY_KEY", "VALUES", "COMMA", "SEMICOLON", 
			"DQUOTA_STRING", "TOKEN", "ERROR_RECONGNIGION"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "sqlParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public sqlParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class RootContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(sqlParser.EOF, 0); }
		public SqlStatementsContext sqlStatements() {
			return getRuleContext(SqlStatementsContext.class,0);
		}
		public RootContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_root; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterRoot(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitRoot(this);
		}
	}

	public final RootContext root() throws RecognitionException {
		RootContext _localctx = new RootContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_root);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << SELECT) | (1L << INSERT) | (1L << DELETE) | (1L << DROP) | (1L << CREATE) | (1L << QUIT) | (1L << EXECFILE) | (1L << SEMICOLON))) != 0)) {
				{
				setState(60);
				sqlStatements();
				}
			}

			setState(63);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SqlStatementsContext extends ParserRuleContext {
		public List<SqlStatementContext> sqlStatement() {
			return getRuleContexts(SqlStatementContext.class);
		}
		public SqlStatementContext sqlStatement(int i) {
			return getRuleContext(SqlStatementContext.class,i);
		}
		public List<EmptyStatementContext> emptyStatement() {
			return getRuleContexts(EmptyStatementContext.class);
		}
		public EmptyStatementContext emptyStatement(int i) {
			return getRuleContext(EmptyStatementContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(sqlParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(sqlParser.SEMICOLON, i);
		}
		public SqlStatementsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sqlStatements; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterSqlStatements(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitSqlStatements(this);
		}
	}

	public final SqlStatementsContext sqlStatements() throws RecognitionException {
		SqlStatementsContext _localctx = new SqlStatementsContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_sqlStatements);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(71);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					setState(69);
					_errHandler.sync(this);
					switch (_input.LA(1)) {
					case SELECT:
					case INSERT:
					case DELETE:
					case DROP:
					case CREATE:
					case QUIT:
					case EXECFILE:
						{
						setState(65);
						sqlStatement();
						setState(66);
						match(SEMICOLON);
						}
						break;
					case SEMICOLON:
						{
						setState(68);
						emptyStatement();
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					} 
				}
				setState(73);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,2,_ctx);
			}
			setState(78);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case SELECT:
			case INSERT:
			case DELETE:
			case DROP:
			case CREATE:
			case QUIT:
			case EXECFILE:
				{
				setState(74);
				sqlStatement();
				{
				setState(75);
				match(SEMICOLON);
				}
				}
				break;
			case SEMICOLON:
				{
				setState(77);
				emptyStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SqlStatementContext extends ParserRuleContext {
		public SelectQueryContext selectQuery() {
			return getRuleContext(SelectQueryContext.class,0);
		}
		public DropIndexQueryContext dropIndexQuery() {
			return getRuleContext(DropIndexQueryContext.class,0);
		}
		public DropTableQueryContext dropTableQuery() {
			return getRuleContext(DropTableQueryContext.class,0);
		}
		public CreateIndexQueryContext createIndexQuery() {
			return getRuleContext(CreateIndexQueryContext.class,0);
		}
		public CreateTableQueryContext createTableQuery() {
			return getRuleContext(CreateTableQueryContext.class,0);
		}
		public InsertQueryContext insertQuery() {
			return getRuleContext(InsertQueryContext.class,0);
		}
		public DeleteQueryContext deleteQuery() {
			return getRuleContext(DeleteQueryContext.class,0);
		}
		public QuitStatementContext quitStatement() {
			return getRuleContext(QuitStatementContext.class,0);
		}
		public ExecfileStatementContext execfileStatement() {
			return getRuleContext(ExecfileStatementContext.class,0);
		}
		public SqlStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_sqlStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterSqlStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitSqlStatement(this);
		}
	}

	public final SqlStatementContext sqlStatement() throws RecognitionException {
		SqlStatementContext _localctx = new SqlStatementContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_sqlStatement);
		try {
			setState(89);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(80);
				selectQuery();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(81);
				dropIndexQuery();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(82);
				dropTableQuery();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(83);
				createIndexQuery();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(84);
				createTableQuery();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(85);
				insertQuery();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(86);
				deleteQuery();
				}
				break;
			case 8:
				enterOuterAlt(_localctx, 8);
				{
				setState(87);
				quitStatement();
				}
				break;
			case 9:
				enterOuterAlt(_localctx, 9);
				{
				setState(88);
				execfileStatement();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class EmptyStatementContext extends ParserRuleContext {
		public TerminalNode SEMICOLON() { return getToken(sqlParser.SEMICOLON, 0); }
		public EmptyStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_emptyStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterEmptyStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitEmptyStatement(this);
		}
	}

	public final EmptyStatementContext emptyStatement() throws RecognitionException {
		EmptyStatementContext _localctx = new EmptyStatementContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_emptyStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91);
			match(SEMICOLON);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SelectQueryContext extends ParserRuleContext {
		public TerminalNode SELECT() { return getToken(sqlParser.SELECT, 0); }
		public TerminalNode WILDCARD() { return getToken(sqlParser.WILDCARD, 0); }
		public TerminalNode FROM() { return getToken(sqlParser.FROM, 0); }
		public SelectTargetContext selectTarget() {
			return getRuleContext(SelectTargetContext.class,0);
		}
		public OptionalWhereClauseContext optionalWhereClause() {
			return getRuleContext(OptionalWhereClauseContext.class,0);
		}
		public SelectQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_selectQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterSelectQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitSelectQuery(this);
		}
	}

	public final SelectQueryContext selectQuery() throws RecognitionException {
		SelectQueryContext _localctx = new SelectQueryContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_selectQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			match(SELECT);
			setState(94);
			match(WILDCARD);
			setState(95);
			match(FROM);
			setState(96);
			selectTarget();
			setState(97);
			optionalWhereClause();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SelectTargetContext extends ParserRuleContext {
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public SelectTargetContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_selectTarget; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterSelectTarget(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitSelectTarget(this);
		}
	}

	public final SelectTargetContext selectTarget() throws RecognitionException {
		SelectTargetContext _localctx = new SelectTargetContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_selectTarget);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			tableName();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OptionalWhereClauseContext extends ParserRuleContext {
		public WhereClauseContext whereClause() {
			return getRuleContext(WhereClauseContext.class,0);
		}
		public OptionalWhereClauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_optionalWhereClause; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterOptionalWhereClause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitOptionalWhereClause(this);
		}
	}

	public final OptionalWhereClauseContext optionalWhereClause() throws RecognitionException {
		OptionalWhereClauseContext _localctx = new OptionalWhereClauseContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_optionalWhereClause);
		try {
			setState(103);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case WHERE:
				enterOuterAlt(_localctx, 1);
				{
				setState(101);
				whereClause();
				}
				break;
			case SEMICOLON:
				enterOuterAlt(_localctx, 2);
				{
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhereClauseContext extends ParserRuleContext {
		public TerminalNode WHERE() { return getToken(sqlParser.WHERE, 0); }
		public WhereConditionsContext whereConditions() {
			return getRuleContext(WhereConditionsContext.class,0);
		}
		public WhereClauseContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whereClause; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterWhereClause(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitWhereClause(this);
		}
	}

	public final WhereClauseContext whereClause() throws RecognitionException {
		WhereClauseContext _localctx = new WhereClauseContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_whereClause);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(105);
			match(WHERE);
			setState(106);
			whereConditions();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhereConditionsContext extends ParserRuleContext {
		public List<WhereConditionContext> whereCondition() {
			return getRuleContexts(WhereConditionContext.class);
		}
		public WhereConditionContext whereCondition(int i) {
			return getRuleContext(WhereConditionContext.class,i);
		}
		public List<WhereOPContext> whereOP() {
			return getRuleContexts(WhereOPContext.class);
		}
		public WhereOPContext whereOP(int i) {
			return getRuleContext(WhereOPContext.class,i);
		}
		public WhereConditionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whereConditions; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterWhereConditions(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitWhereConditions(this);
		}
	}

	public final WhereConditionsContext whereConditions() throws RecognitionException {
		WhereConditionsContext _localctx = new WhereConditionsContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_whereConditions);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			whereCondition();
			setState(114);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==AND) {
				{
				{
				setState(109);
				whereOP();
				setState(110);
				whereCondition();
				}
				}
				setState(116);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhereConditionContext extends ParserRuleContext {
		public ColumnNameContext columnName() {
			return getRuleContext(ColumnNameContext.class,0);
		}
		public OpContext op() {
			return getRuleContext(OpContext.class,0);
		}
		public LiteralContext literal() {
			return getRuleContext(LiteralContext.class,0);
		}
		public WhereConditionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whereCondition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterWhereCondition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitWhereCondition(this);
		}
	}

	public final WhereConditionContext whereCondition() throws RecognitionException {
		WhereConditionContext _localctx = new WhereConditionContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_whereCondition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(117);
			columnName();
			setState(118);
			op();
			setState(119);
			literal();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhereOPContext extends ParserRuleContext {
		public TerminalNode AND() { return getToken(sqlParser.AND, 0); }
		public WhereOPContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whereOP; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterWhereOP(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitWhereOP(this);
		}
	}

	public final WhereOPContext whereOP() throws RecognitionException {
		WhereOPContext _localctx = new WhereOPContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_whereOP);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(121);
			match(AND);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DropIndexQueryContext extends ParserRuleContext {
		public TerminalNode DROP() { return getToken(sqlParser.DROP, 0); }
		public TerminalNode INDEX() { return getToken(sqlParser.INDEX, 0); }
		public IndexNameContext indexName() {
			return getRuleContext(IndexNameContext.class,0);
		}
		public DropIndexQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dropIndexQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterDropIndexQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitDropIndexQuery(this);
		}
	}

	public final DropIndexQueryContext dropIndexQuery() throws RecognitionException {
		DropIndexQueryContext _localctx = new DropIndexQueryContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_dropIndexQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			match(DROP);
			setState(124);
			match(INDEX);
			setState(125);
			indexName();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DropTableQueryContext extends ParserRuleContext {
		public TerminalNode DROP() { return getToken(sqlParser.DROP, 0); }
		public TerminalNode TABLE() { return getToken(sqlParser.TABLE, 0); }
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public DropTableQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_dropTableQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterDropTableQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitDropTableQuery(this);
		}
	}

	public final DropTableQueryContext dropTableQuery() throws RecognitionException {
		DropTableQueryContext _localctx = new DropTableQueryContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_dropTableQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(127);
			match(DROP);
			setState(128);
			match(TABLE);
			setState(129);
			tableName();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CreateIndexQueryContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(sqlParser.CREATE, 0); }
		public TerminalNode INDEX() { return getToken(sqlParser.INDEX, 0); }
		public IndexNameContext indexName() {
			return getRuleContext(IndexNameContext.class,0);
		}
		public TerminalNode ON() { return getToken(sqlParser.ON, 0); }
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public TerminalNode OPEN_BRACKET() { return getToken(sqlParser.OPEN_BRACKET, 0); }
		public ColumnNameContext columnName() {
			return getRuleContext(ColumnNameContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(sqlParser.CLOSE_BRACKET, 0); }
		public CreateIndexQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_createIndexQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterCreateIndexQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitCreateIndexQuery(this);
		}
	}

	public final CreateIndexQueryContext createIndexQuery() throws RecognitionException {
		CreateIndexQueryContext _localctx = new CreateIndexQueryContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_createIndexQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(131);
			match(CREATE);
			setState(132);
			match(INDEX);
			setState(133);
			indexName();
			setState(134);
			match(ON);
			setState(135);
			tableName();
			setState(136);
			match(OPEN_BRACKET);
			setState(137);
			columnName();
			setState(138);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CreateTableQueryContext extends ParserRuleContext {
		public TerminalNode CREATE() { return getToken(sqlParser.CREATE, 0); }
		public TerminalNode TABLE() { return getToken(sqlParser.TABLE, 0); }
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public TerminalNode OPEN_BRACKET() { return getToken(sqlParser.OPEN_BRACKET, 0); }
		public ColumnDefinitionsContext columnDefinitions() {
			return getRuleContext(ColumnDefinitionsContext.class,0);
		}
		public PrimaryKeyDefinitionContext primaryKeyDefinition() {
			return getRuleContext(PrimaryKeyDefinitionContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(sqlParser.CLOSE_BRACKET, 0); }
		public CreateTableQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_createTableQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterCreateTableQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitCreateTableQuery(this);
		}
	}

	public final CreateTableQueryContext createTableQuery() throws RecognitionException {
		CreateTableQueryContext _localctx = new CreateTableQueryContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_createTableQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(140);
			match(CREATE);
			setState(141);
			match(TABLE);
			setState(142);
			tableName();
			setState(143);
			match(OPEN_BRACKET);
			setState(144);
			columnDefinitions();
			setState(145);
			primaryKeyDefinition();
			setState(146);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ColumnDefinitionsContext extends ParserRuleContext {
		public List<ColumnDefinitionContext> columnDefinition() {
			return getRuleContexts(ColumnDefinitionContext.class);
		}
		public ColumnDefinitionContext columnDefinition(int i) {
			return getRuleContext(ColumnDefinitionContext.class,i);
		}
		public ColumnDefinitionsContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_columnDefinitions; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterColumnDefinitions(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitColumnDefinitions(this);
		}
	}

	public final ColumnDefinitionsContext columnDefinitions() throws RecognitionException {
		ColumnDefinitionsContext _localctx = new ColumnDefinitionsContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_columnDefinitions);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(149); 
			_errHandler.sync(this);
			_la = _input.LA(1);
			do {
				{
				{
				setState(148);
				columnDefinition();
				}
				}
				setState(151); 
				_errHandler.sync(this);
				_la = _input.LA(1);
			} while ( _la==TOKEN );
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ColumnDefinitionContext extends ParserRuleContext {
		public ColumnDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_columnDefinition; }
	 
		public ColumnDefinitionContext() { }
		public void copyFrom(ColumnDefinitionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NonUniqueColumnDefinitionContext extends ColumnDefinitionContext {
		public ColumnNameContext columnName() {
			return getRuleContext(ColumnNameContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(sqlParser.COMMA, 0); }
		public NonUniqueColumnDefinitionContext(ColumnDefinitionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterNonUniqueColumnDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitNonUniqueColumnDefinition(this);
		}
	}
	public static class UniqueColumnDefinitionContext extends ColumnDefinitionContext {
		public ColumnNameContext columnName() {
			return getRuleContext(ColumnNameContext.class,0);
		}
		public TypeContext type() {
			return getRuleContext(TypeContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(sqlParser.COMMA, 0); }
		public TerminalNode UNIQUE() { return getToken(sqlParser.UNIQUE, 0); }
		public UniqueColumnDefinitionContext(ColumnDefinitionContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterUniqueColumnDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitUniqueColumnDefinition(this);
		}
	}

	public final ColumnDefinitionContext columnDefinition() throws RecognitionException {
		ColumnDefinitionContext _localctx = new ColumnDefinitionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_columnDefinition);
		try {
			setState(162);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				_localctx = new NonUniqueColumnDefinitionContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(153);
				columnName();
				setState(154);
				type();
				setState(155);
				match(COMMA);
				}
				break;
			case 2:
				_localctx = new UniqueColumnDefinitionContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(157);
				columnName();
				setState(158);
				type();
				setState(159);
				match(COMMA);
				setState(160);
				match(UNIQUE);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PrimaryKeyDefinitionContext extends ParserRuleContext {
		public TerminalNode PRIMARY_KEY() { return getToken(sqlParser.PRIMARY_KEY, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(sqlParser.OPEN_BRACKET, 0); }
		public ColumnNameContext columnName() {
			return getRuleContext(ColumnNameContext.class,0);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(sqlParser.CLOSE_BRACKET, 0); }
		public PrimaryKeyDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primaryKeyDefinition; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterPrimaryKeyDefinition(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitPrimaryKeyDefinition(this);
		}
	}

	public final PrimaryKeyDefinitionContext primaryKeyDefinition() throws RecognitionException {
		PrimaryKeyDefinitionContext _localctx = new PrimaryKeyDefinitionContext(_ctx, getState());
		enterRule(_localctx, 34, RULE_primaryKeyDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(164);
			match(PRIMARY_KEY);
			setState(165);
			match(OPEN_BRACKET);
			setState(166);
			columnName();
			setState(167);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InsertQueryContext extends ParserRuleContext {
		public TerminalNode INSERT() { return getToken(sqlParser.INSERT, 0); }
		public TerminalNode INTO() { return getToken(sqlParser.INTO, 0); }
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public TerminalNode VALUES() { return getToken(sqlParser.VALUES, 0); }
		public LiteralValuesContext literalValues() {
			return getRuleContext(LiteralValuesContext.class,0);
		}
		public InsertQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_insertQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterInsertQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitInsertQuery(this);
		}
	}

	public final InsertQueryContext insertQuery() throws RecognitionException {
		InsertQueryContext _localctx = new InsertQueryContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_insertQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(169);
			match(INSERT);
			setState(170);
			match(INTO);
			setState(171);
			tableName();
			setState(172);
			match(VALUES);
			setState(173);
			literalValues();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralValuesContext extends ParserRuleContext {
		public TerminalNode OPEN_BRACKET() { return getToken(sqlParser.OPEN_BRACKET, 0); }
		public List<LiteralContext> literal() {
			return getRuleContexts(LiteralContext.class);
		}
		public LiteralContext literal(int i) {
			return getRuleContext(LiteralContext.class,i);
		}
		public TerminalNode CLOSE_BRACKET() { return getToken(sqlParser.CLOSE_BRACKET, 0); }
		public List<TerminalNode> COMMA() { return getTokens(sqlParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(sqlParser.COMMA, i);
		}
		public LiteralValuesContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literalValues; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterLiteralValues(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitLiteralValues(this);
		}
	}

	public final LiteralValuesContext literalValues() throws RecognitionException {
		LiteralValuesContext _localctx = new LiteralValuesContext(_ctx, getState());
		enterRule(_localctx, 38, RULE_literalValues);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(175);
			match(OPEN_BRACKET);
			setState(176);
			literal();
			setState(181);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==COMMA) {
				{
				{
				setState(177);
				match(COMMA);
				setState(178);
				literal();
				}
				}
				setState(183);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(184);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeleteQueryContext extends ParserRuleContext {
		public TerminalNode DELETE() { return getToken(sqlParser.DELETE, 0); }
		public TerminalNode FROM() { return getToken(sqlParser.FROM, 0); }
		public TableNameContext tableName() {
			return getRuleContext(TableNameContext.class,0);
		}
		public OptionalWhereClauseContext optionalWhereClause() {
			return getRuleContext(OptionalWhereClauseContext.class,0);
		}
		public DeleteQueryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_deleteQuery; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterDeleteQuery(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitDeleteQuery(this);
		}
	}

	public final DeleteQueryContext deleteQuery() throws RecognitionException {
		DeleteQueryContext _localctx = new DeleteQueryContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_deleteQuery);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(186);
			match(DELETE);
			setState(187);
			match(FROM);
			setState(188);
			tableName();
			setState(189);
			optionalWhereClause();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class QuitStatementContext extends ParserRuleContext {
		public TerminalNode QUIT() { return getToken(sqlParser.QUIT, 0); }
		public QuitStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_quitStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterQuitStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitQuitStatement(this);
		}
	}

	public final QuitStatementContext quitStatement() throws RecognitionException {
		QuitStatementContext _localctx = new QuitStatementContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_quitStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(191);
			match(QUIT);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExecfileStatementContext extends ParserRuleContext {
		public TerminalNode EXECFILE() { return getToken(sqlParser.EXECFILE, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(sqlParser.STRING_LITERAL, 0); }
		public ExecfileStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_execfileStatement; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterExecfileStatement(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitExecfileStatement(this);
		}
	}

	public final ExecfileStatementContext execfileStatement() throws RecognitionException {
		ExecfileStatementContext _localctx = new ExecfileStatementContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_execfileStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(193);
			match(EXECFILE);
			setState(194);
			match(STRING_LITERAL);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TableNameContext extends ParserRuleContext {
		public TerminalNode TOKEN() { return getToken(sqlParser.TOKEN, 0); }
		public TableNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_tableName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterTableName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitTableName(this);
		}
	}

	public final TableNameContext tableName() throws RecognitionException {
		TableNameContext _localctx = new TableNameContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_tableName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(196);
			match(TOKEN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ColumnNameContext extends ParserRuleContext {
		public TerminalNode TOKEN() { return getToken(sqlParser.TOKEN, 0); }
		public ColumnNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_columnName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterColumnName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitColumnName(this);
		}
	}

	public final ColumnNameContext columnName() throws RecognitionException {
		ColumnNameContext _localctx = new ColumnNameContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_columnName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(198);
			match(TOKEN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IndexNameContext extends ParserRuleContext {
		public TerminalNode TOKEN() { return getToken(sqlParser.TOKEN, 0); }
		public IndexNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_indexName; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterIndexName(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitIndexName(this);
		}
	}

	public final IndexNameContext indexName() throws RecognitionException {
		IndexNameContext _localctx = new IndexNameContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_indexName);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(200);
			match(TOKEN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralContext extends ParserRuleContext {
		public TerminalNode DECIMAL_LITERAL() { return getToken(sqlParser.DECIMAL_LITERAL, 0); }
		public TerminalNode STRING_LITERAL() { return getToken(sqlParser.STRING_LITERAL, 0); }
		public TerminalNode REAL_LITERAL() { return getToken(sqlParser.REAL_LITERAL, 0); }
		public LiteralContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literal; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterLiteral(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitLiteral(this);
		}
	}

	public final LiteralContext literal() throws RecognitionException {
		LiteralContext _localctx = new LiteralContext(_ctx, getState());
		enterRule(_localctx, 52, RULE_literal);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(202);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << DECIMAL_LITERAL) | (1L << STRING_LITERAL) | (1L << REAL_LITERAL))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OpContext extends ParserRuleContext {
		public TerminalNode EQUAL() { return getToken(sqlParser.EQUAL, 0); }
		public TerminalNode NOT_EQUAL() { return getToken(sqlParser.NOT_EQUAL, 0); }
		public TerminalNode SMALLER() { return getToken(sqlParser.SMALLER, 0); }
		public TerminalNode SMALLER_EQUAL() { return getToken(sqlParser.SMALLER_EQUAL, 0); }
		public TerminalNode GREATER() { return getToken(sqlParser.GREATER, 0); }
		public TerminalNode GREATER_EQUAL() { return getToken(sqlParser.GREATER_EQUAL, 0); }
		public OpContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_op; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterOp(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitOp(this);
		}
	}

	public final OpContext op() throws RecognitionException {
		OpContext _localctx = new OpContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_op);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(204);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << EQUAL) | (1L << NOT_EQUAL) | (1L << SMALLER) | (1L << GREATER) | (1L << SMALLER_EQUAL) | (1L << GREATER_EQUAL))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeContext extends ParserRuleContext {
		public TypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_type; }
	 
		public TypeContext() { }
		public void copyFrom(TypeContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class IntTypeDefContext extends TypeContext {
		public TerminalNode INT() { return getToken(sqlParser.INT, 0); }
		public IntTypeDefContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterIntTypeDef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitIntTypeDef(this);
		}
	}
	public static class CharTypeDefContext extends TypeContext {
		public CharTypeContext charType() {
			return getRuleContext(CharTypeContext.class,0);
		}
		public CharTypeDefContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterCharTypeDef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitCharTypeDef(this);
		}
	}
	public static class FloatTypeDefContext extends TypeContext {
		public TerminalNode FLOAT() { return getToken(sqlParser.FLOAT, 0); }
		public FloatTypeDefContext(TypeContext ctx) { copyFrom(ctx); }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterFloatTypeDef(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitFloatTypeDef(this);
		}
	}

	public final TypeContext type() throws RecognitionException {
		TypeContext _localctx = new TypeContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_type);
		try {
			setState(209);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CHAR:
				_localctx = new CharTypeDefContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(206);
				charType();
				}
				break;
			case INT:
				_localctx = new IntTypeDefContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(207);
				match(INT);
				}
				break;
			case FLOAT:
				_localctx = new FloatTypeDefContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(208);
				match(FLOAT);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CharTypeContext extends ParserRuleContext {
		public TerminalNode CHAR() { return getToken(sqlParser.CHAR, 0); }
		public TerminalNode OPEN_BRACKET() { return getToken(sqlParser.OPEN_BRACKET, 0); }
		public TerminalNode DECIMAL_LITERAL() { return getToken(sqlParser.DECIMAL_LITERAL, 0); }
		public TerminalNode CLOSE_BRACKET() { return getToken(sqlParser.CLOSE_BRACKET, 0); }
		public CharTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_charType; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).enterCharType(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof sqlParserListener ) ((sqlParserListener)listener).exitCharType(this);
		}
	}

	public final CharTypeContext charType() throws RecognitionException {
		CharTypeContext _localctx = new CharTypeContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_charType);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(211);
			match(CHAR);
			setState(212);
			match(OPEN_BRACKET);
			setState(213);
			match(DECIMAL_LITERAL);
			setState(214);
			match(CLOSE_BRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3-\u00db\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\3\2\5\2@"+
		"\n\2\3\2\3\2\3\3\3\3\3\3\3\3\7\3H\n\3\f\3\16\3K\13\3\3\3\3\3\3\3\3\3\5"+
		"\3Q\n\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4\\\n\4\3\5\3\5\3\6\3\6"+
		"\3\6\3\6\3\6\3\6\3\7\3\7\3\b\3\b\5\bj\n\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n"+
		"\7\ns\n\n\f\n\16\nv\13\n\3\13\3\13\3\13\3\13\3\f\3\f\3\r\3\r\3\r\3\r\3"+
		"\16\3\16\3\16\3\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3"+
		"\20\3\20\3\20\3\20\3\20\3\20\3\20\3\21\6\21\u0098\n\21\r\21\16\21\u0099"+
		"\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\3\22\5\22\u00a5\n\22\3\23\3\23"+
		"\3\23\3\23\3\23\3\24\3\24\3\24\3\24\3\24\3\24\3\25\3\25\3\25\3\25\7\25"+
		"\u00b6\n\25\f\25\16\25\u00b9\13\25\3\25\3\25\3\26\3\26\3\26\3\26\3\26"+
		"\3\27\3\27\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\34\3\34\3\35"+
		"\3\35\3\36\3\36\3\36\5\36\u00d4\n\36\3\37\3\37\3\37\3\37\3\37\3\37\2\2"+
		" \2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<\2\4\3"+
		"\2$&\3\2\30\35\2\u00cf\2?\3\2\2\2\4I\3\2\2\2\6[\3\2\2\2\b]\3\2\2\2\n_"+
		"\3\2\2\2\fe\3\2\2\2\16i\3\2\2\2\20k\3\2\2\2\22n\3\2\2\2\24w\3\2\2\2\26"+
		"{\3\2\2\2\30}\3\2\2\2\32\u0081\3\2\2\2\34\u0085\3\2\2\2\36\u008e\3\2\2"+
		"\2 \u0097\3\2\2\2\"\u00a4\3\2\2\2$\u00a6\3\2\2\2&\u00ab\3\2\2\2(\u00b1"+
		"\3\2\2\2*\u00bc\3\2\2\2,\u00c1\3\2\2\2.\u00c3\3\2\2\2\60\u00c6\3\2\2\2"+
		"\62\u00c8\3\2\2\2\64\u00ca\3\2\2\2\66\u00cc\3\2\2\28\u00ce\3\2\2\2:\u00d3"+
		"\3\2\2\2<\u00d5\3\2\2\2>@\5\4\3\2?>\3\2\2\2?@\3\2\2\2@A\3\2\2\2AB\7\2"+
		"\2\3B\3\3\2\2\2CD\5\6\4\2DE\7*\2\2EH\3\2\2\2FH\5\b\5\2GC\3\2\2\2GF\3\2"+
		"\2\2HK\3\2\2\2IG\3\2\2\2IJ\3\2\2\2JP\3\2\2\2KI\3\2\2\2LM\5\6\4\2MN\7*"+
		"\2\2NQ\3\2\2\2OQ\5\b\5\2PL\3\2\2\2PO\3\2\2\2Q\5\3\2\2\2R\\\5\n\6\2S\\"+
		"\5\30\r\2T\\\5\32\16\2U\\\5\34\17\2V\\\5\36\20\2W\\\5&\24\2X\\\5*\26\2"+
		"Y\\\5,\27\2Z\\\5.\30\2[R\3\2\2\2[S\3\2\2\2[T\3\2\2\2[U\3\2\2\2[V\3\2\2"+
		"\2[W\3\2\2\2[X\3\2\2\2[Y\3\2\2\2[Z\3\2\2\2\\\7\3\2\2\2]^\7*\2\2^\t\3\2"+
		"\2\2_`\7\7\2\2`a\7\20\2\2ab\7\21\2\2bc\5\f\7\2cd\5\16\b\2d\13\3\2\2\2"+
		"ef\5\60\31\2f\r\3\2\2\2gj\5\20\t\2hj\3\2\2\2ig\3\2\2\2ih\3\2\2\2j\17\3"+
		"\2\2\2kl\7\27\2\2lm\5\22\n\2m\21\3\2\2\2nt\5\24\13\2op\5\26\f\2pq\5\24"+
		"\13\2qs\3\2\2\2ro\3\2\2\2sv\3\2\2\2tr\3\2\2\2tu\3\2\2\2u\23\3\2\2\2vt"+
		"\3\2\2\2wx\5\62\32\2xy\58\35\2yz\5\66\34\2z\25\3\2\2\2{|\7\36\2\2|\27"+
		"\3\2\2\2}~\7\n\2\2~\177\7\17\2\2\177\u0080\5\64\33\2\u0080\31\3\2\2\2"+
		"\u0081\u0082\7\n\2\2\u0082\u0083\7\16\2\2\u0083\u0084\5\60\31\2\u0084"+
		"\33\3\2\2\2\u0085\u0086\7\13\2\2\u0086\u0087\7\17\2\2\u0087\u0088\5\64"+
		"\33\2\u0088\u0089\7\23\2\2\u0089\u008a\5\60\31\2\u008a\u008b\7\25\2\2"+
		"\u008b\u008c\5\62\32\2\u008c\u008d\7\26\2\2\u008d\35\3\2\2\2\u008e\u008f"+
		"\7\13\2\2\u008f\u0090\7\16\2\2\u0090\u0091\5\60\31\2\u0091\u0092\7\25"+
		"\2\2\u0092\u0093\5 \21\2\u0093\u0094\5$\23\2\u0094\u0095\7\26\2\2\u0095"+
		"\37\3\2\2\2\u0096\u0098\5\"\22\2\u0097\u0096\3\2\2\2\u0098\u0099\3\2\2"+
		"\2\u0099\u0097\3\2\2\2\u0099\u009a\3\2\2\2\u009a!\3\2\2\2\u009b\u009c"+
		"\5\62\32\2\u009c\u009d\5:\36\2\u009d\u009e\7)\2\2\u009e\u00a5\3\2\2\2"+
		"\u009f\u00a0\5\62\32\2\u00a0\u00a1\5:\36\2\u00a1\u00a2\7)\2\2\u00a2\u00a3"+
		"\7#\2\2\u00a3\u00a5\3\2\2\2\u00a4\u009b\3\2\2\2\u00a4\u009f\3\2\2\2\u00a5"+
		"#\3\2\2\2\u00a6\u00a7\7\'\2\2\u00a7\u00a8\7\25\2\2\u00a8\u00a9\5\62\32"+
		"\2\u00a9\u00aa\7\26\2\2\u00aa%\3\2\2\2\u00ab\u00ac\7\b\2\2\u00ac\u00ad"+
		"\7\22\2\2\u00ad\u00ae\5\60\31\2\u00ae\u00af\7(\2\2\u00af\u00b0\5(\25\2"+
		"\u00b0\'\3\2\2\2\u00b1\u00b2\7\25\2\2\u00b2\u00b7\5\66\34\2\u00b3\u00b4"+
		"\7)\2\2\u00b4\u00b6\5\66\34\2\u00b5\u00b3\3\2\2\2\u00b6\u00b9\3\2\2\2"+
		"\u00b7\u00b5\3\2\2\2\u00b7\u00b8\3\2\2\2\u00b8\u00ba\3\2\2\2\u00b9\u00b7"+
		"\3\2\2\2\u00ba\u00bb\7\26\2\2\u00bb)\3\2\2\2\u00bc\u00bd\7\t\2\2\u00bd"+
		"\u00be\7\21\2\2\u00be\u00bf\5\60\31\2\u00bf\u00c0\5\16\b\2\u00c0+\3\2"+
		"\2\2\u00c1\u00c2\7\f\2\2\u00c2-\3\2\2\2\u00c3\u00c4\7\r\2\2\u00c4\u00c5"+
		"\7%\2\2\u00c5/\3\2\2\2\u00c6\u00c7\7,\2\2\u00c7\61\3\2\2\2\u00c8\u00c9"+
		"\7,\2\2\u00c9\63\3\2\2\2\u00ca\u00cb\7,\2\2\u00cb\65\3\2\2\2\u00cc\u00cd"+
		"\t\2\2\2\u00cd\67\3\2\2\2\u00ce\u00cf\t\3\2\2\u00cf9\3\2\2\2\u00d0\u00d4"+
		"\5<\37\2\u00d1\u00d4\7!\2\2\u00d2\u00d4\7\"\2\2\u00d3\u00d0\3\2\2\2\u00d3"+
		"\u00d1\3\2\2\2\u00d3\u00d2\3\2\2\2\u00d4;\3\2\2\2\u00d5\u00d6\7 \2\2\u00d6"+
		"\u00d7\7\25\2\2\u00d7\u00d8\7$\2\2\u00d8\u00d9\7\26\2\2\u00d9=\3\2\2\2"+
		"\r?GIP[it\u0099\u00a4\u00b7\u00d3";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}