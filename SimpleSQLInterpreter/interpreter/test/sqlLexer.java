// Generated from sqlLexer.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class sqlLexer extends Lexer {
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
		ERRORCHANNEL=2, MYSQLCOMMENT=3;
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN", "ERRORCHANNEL", "MYSQLCOMMENT"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"SPACE", "SPEC_MYSQL_COMMENT", "COMMENT_INPUT", "LINE_COMMENT", "SELECT", 
			"INSERT", "DELETE", "DROP", "CREATE", "QUIT", "EXECFILE", "TABLE", "INDEX", 
			"WILDCARD", "FROM", "INTO", "ON", "QUOTE", "OPEN_BRACKET", "CLOSE_BRACKET", 
			"WHERE", "EQUAL", "NOT_EQUAL", "SMALLER", "GREATER", "SMALLER_EQUAL", 
			"GREATER_EQUAL", "AND", "OR", "CHAR", "INT", "FLOAT", "UNIQUE", "DECIMAL_LITERAL", 
			"STRING_LITERAL", "REAL_LITERAL", "PRIMARY_KEY", "VALUES", "COMMA", "SEMICOLON", 
			"EXPONENT_NUM_PART", "DQUOTA_STRING", "DEC_DIGIT", "TOKEN", "COLUMN_NAME", 
			"TABLE_NAME", "INDEX_NAME", "ERROR_RECONGNIGION"
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


	public sqlLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "sqlLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2-\u01c1\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\3\2\6\2e\n\2\r\2\16\2f\3\2"+
		"\3\2\3\3\3\3\3\3\3\3\3\3\6\3p\n\3\r\3\16\3q\3\3\3\3\3\3\3\3\3\3\3\4\3"+
		"\4\3\4\3\4\7\4}\n\4\f\4\16\4\u0080\13\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3"+
		"\5\3\5\5\5\u008b\n\5\3\5\7\5\u008e\n\5\f\5\16\5\u0091\13\5\3\5\5\5\u0094"+
		"\n\5\3\5\3\5\5\5\u0098\n\5\3\5\3\5\3\5\3\5\5\5\u009e\n\5\3\5\3\5\5\5\u00a2"+
		"\n\5\5\5\u00a4\n\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7"+
		"\3\7\3\7\3\7\3\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3"+
		"\n\3\n\3\n\3\n\3\n\3\13\3\13\3\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3"+
		"\f\3\f\3\f\3\r\3\r\3\r\3\r\3\r\3\r\3\16\3\16\3\16\3\16\3\16\3\16\3\17"+
		"\3\17\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\3\21\3\22\3\22\3\22"+
		"\3\23\3\23\3\24\3\24\3\25\3\25\3\26\3\26\3\26\3\26\3\26\3\26\3\27\3\27"+
		"\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\33\3\33\3\33\3\34\3\34\3\34\3\35"+
		"\3\35\3\35\3\35\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37\3 \3 \3 \3 \3"+
		"!\3!\3!\3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3#\5#\u012b\n#\3#\6#\u012e"+
		"\n#\r#\16#\u012f\3$\3$\3%\5%\u0135\n%\3%\6%\u0138\n%\r%\16%\u0139\5%\u013c"+
		"\n%\3%\3%\6%\u0140\n%\r%\16%\u0141\3%\5%\u0145\n%\3%\6%\u0148\n%\r%\16"+
		"%\u0149\3%\3%\3%\3%\5%\u0150\n%\3%\6%\u0153\n%\r%\16%\u0154\5%\u0157\n"+
		"%\3%\3%\6%\u015b\n%\r%\16%\u015c\3%\3%\3%\5%\u0162\n%\3%\6%\u0165\n%\r"+
		"%\16%\u0166\3%\3%\5%\u016b\n%\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\3&\3\'"+
		"\3\'\3\'\3\'\3\'\3\'\3\'\3(\3(\3)\3)\3*\3*\5*\u0186\n*\3*\6*\u0189\n*"+
		"\r*\16*\u018a\3+\3+\7+\u018f\n+\f+\16+\u0192\13+\3+\3+\3,\3,\3-\3-\3-"+
		"\5-\u019b\n-\3.\6.\u019e\n.\r.\16.\u019f\3.\7.\u01a3\n.\f.\16.\u01a6\13"+
		".\3/\6/\u01a9\n/\r/\16/\u01aa\3/\7/\u01ae\n/\f/\16/\u01b1\13/\3\60\6\60"+
		"\u01b4\n\60\r\60\16\60\u01b5\3\60\7\60\u01b9\n\60\f\60\16\60\u01bc\13"+
		"\60\3\61\3\61\3\61\3\61\5q~\u0190\2\62\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21"+
		"\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30"+
		"/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G%I&K\'M(O)Q*S\2U+W\2Y"+
		",[\2]\2_\2a-\3\2\t\5\2\13\f\17\17\"\"\4\2\f\f\17\17\4\2$$))\4\2--//\3"+
		"\2\62;\4\2C\\c|\5\2\62;C\\c|\2\u01e1\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2"+
		"\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23"+
		"\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2"+
		"\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2"+
		"\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3"+
		"\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2"+
		"\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2\2"+
		"\2O\3\2\2\2\2Q\3\2\2\2\2U\3\2\2\2\2Y\3\2\2\2\2a\3\2\2\2\3d\3\2\2\2\5j"+
		"\3\2\2\2\7x\3\2\2\2\t\u00a3\3\2\2\2\13\u00a7\3\2\2\2\r\u00ae\3\2\2\2\17"+
		"\u00b5\3\2\2\2\21\u00bc\3\2\2\2\23\u00c1\3\2\2\2\25\u00c8\3\2\2\2\27\u00cd"+
		"\3\2\2\2\31\u00d6\3\2\2\2\33\u00dc\3\2\2\2\35\u00e2\3\2\2\2\37\u00e4\3"+
		"\2\2\2!\u00e9\3\2\2\2#\u00ee\3\2\2\2%\u00f1\3\2\2\2\'\u00f3\3\2\2\2)\u00f5"+
		"\3\2\2\2+\u00f7\3\2\2\2-\u00fd\3\2\2\2/\u00ff\3\2\2\2\61\u0102\3\2\2\2"+
		"\63\u0104\3\2\2\2\65\u0106\3\2\2\2\67\u0109\3\2\2\29\u010c\3\2\2\2;\u0110"+
		"\3\2\2\2=\u0113\3\2\2\2?\u0118\3\2\2\2A\u011c\3\2\2\2C\u0122\3\2\2\2E"+
		"\u012a\3\2\2\2G\u0131\3\2\2\2I\u016a\3\2\2\2K\u016c\3\2\2\2M\u0178\3\2"+
		"\2\2O\u017f\3\2\2\2Q\u0181\3\2\2\2S\u0183\3\2\2\2U\u018c\3\2\2\2W\u0195"+
		"\3\2\2\2Y\u019a\3\2\2\2[\u019d\3\2\2\2]\u01a8\3\2\2\2_\u01b3\3\2\2\2a"+
		"\u01bd\3\2\2\2ce\t\2\2\2dc\3\2\2\2ef\3\2\2\2fd\3\2\2\2fg\3\2\2\2gh\3\2"+
		"\2\2hi\b\2\2\2i\4\3\2\2\2jk\7\61\2\2kl\7,\2\2lm\7#\2\2mo\3\2\2\2np\13"+
		"\2\2\2on\3\2\2\2pq\3\2\2\2qr\3\2\2\2qo\3\2\2\2rs\3\2\2\2st\7,\2\2tu\7"+
		"\61\2\2uv\3\2\2\2vw\b\3\3\2w\6\3\2\2\2xy\7\61\2\2yz\7,\2\2z~\3\2\2\2{"+
		"}\13\2\2\2|{\3\2\2\2}\u0080\3\2\2\2~\177\3\2\2\2~|\3\2\2\2\177\u0081\3"+
		"\2\2\2\u0080~\3\2\2\2\u0081\u0082\7,\2\2\u0082\u0083\7\61\2\2\u0083\u0084"+
		"\3\2\2\2\u0084\u0085\b\4\2\2\u0085\b\3\2\2\2\u0086\u0087\7/\2\2\u0087"+
		"\u0088\7/\2\2\u0088\u008b\7\"\2\2\u0089\u008b\7%\2\2\u008a\u0086\3\2\2"+
		"\2\u008a\u0089\3\2\2\2\u008b\u008f\3\2\2\2\u008c\u008e\n\3\2\2\u008d\u008c"+
		"\3\2\2\2\u008e\u0091\3\2\2\2\u008f\u008d\3\2\2\2\u008f\u0090\3\2\2\2\u0090"+
		"\u0097\3\2\2\2\u0091\u008f\3\2\2\2\u0092\u0094\7\17\2\2\u0093\u0092\3"+
		"\2\2\2\u0093\u0094\3\2\2\2\u0094\u0095\3\2\2\2\u0095\u0098\7\f\2\2\u0096"+
		"\u0098\7\2\2\3\u0097\u0093\3\2\2\2\u0097\u0096\3\2\2\2\u0098\u00a4\3\2"+
		"\2\2\u0099\u009a\7/\2\2\u009a\u009b\7/\2\2\u009b\u00a1\3\2\2\2\u009c\u009e"+
		"\7\17\2\2\u009d\u009c\3\2\2\2\u009d\u009e\3\2\2\2\u009e\u009f\3\2\2\2"+
		"\u009f\u00a2\7\f\2\2\u00a0\u00a2\7\2\2\3\u00a1\u009d\3\2\2\2\u00a1\u00a0"+
		"\3\2\2\2\u00a2\u00a4\3\2\2\2\u00a3\u008a\3\2\2\2\u00a3\u0099\3\2\2\2\u00a4"+
		"\u00a5\3\2\2\2\u00a5\u00a6\b\5\2\2\u00a6\n\3\2\2\2\u00a7\u00a8\7u\2\2"+
		"\u00a8\u00a9\7g\2\2\u00a9\u00aa\7n\2\2\u00aa\u00ab\7g\2\2\u00ab\u00ac"+
		"\7e\2\2\u00ac\u00ad\7v\2\2\u00ad\f\3\2\2\2\u00ae\u00af\7k\2\2\u00af\u00b0"+
		"\7p\2\2\u00b0\u00b1\7u\2\2\u00b1\u00b2\7g\2\2\u00b2\u00b3\7t\2\2\u00b3"+
		"\u00b4\7v\2\2\u00b4\16\3\2\2\2\u00b5\u00b6\7f\2\2\u00b6\u00b7\7g\2\2\u00b7"+
		"\u00b8\7n\2\2\u00b8\u00b9\7g\2\2\u00b9\u00ba\7v\2\2\u00ba\u00bb\7g\2\2"+
		"\u00bb\20\3\2\2\2\u00bc\u00bd\7f\2\2\u00bd\u00be\7t\2\2\u00be\u00bf\7"+
		"q\2\2\u00bf\u00c0\7r\2\2\u00c0\22\3\2\2\2\u00c1\u00c2\7e\2\2\u00c2\u00c3"+
		"\7t\2\2\u00c3\u00c4\7g\2\2\u00c4\u00c5\7c\2\2\u00c5\u00c6\7v\2\2\u00c6"+
		"\u00c7\7g\2\2\u00c7\24\3\2\2\2\u00c8\u00c9\7s\2\2\u00c9\u00ca\7w\2\2\u00ca"+
		"\u00cb\7k\2\2\u00cb\u00cc\7v\2\2\u00cc\26\3\2\2\2\u00cd\u00ce\7g\2\2\u00ce"+
		"\u00cf\7z\2\2\u00cf\u00d0\7g\2\2\u00d0\u00d1\7e\2\2\u00d1\u00d2\7h\2\2"+
		"\u00d2\u00d3\7k\2\2\u00d3\u00d4\7n\2\2\u00d4\u00d5\7g\2\2\u00d5\30\3\2"+
		"\2\2\u00d6\u00d7\7v\2\2\u00d7\u00d8\7c\2\2\u00d8\u00d9\7d\2\2\u00d9\u00da"+
		"\7n\2\2\u00da\u00db\7g\2\2\u00db\32\3\2\2\2\u00dc\u00dd\7k\2\2\u00dd\u00de"+
		"\7p\2\2\u00de\u00df\7f\2\2\u00df\u00e0\7g\2\2\u00e0\u00e1\7z\2\2\u00e1"+
		"\34\3\2\2\2\u00e2\u00e3\7,\2\2\u00e3\36\3\2\2\2\u00e4\u00e5\7h\2\2\u00e5"+
		"\u00e6\7t\2\2\u00e6\u00e7\7q\2\2\u00e7\u00e8\7o\2\2\u00e8 \3\2\2\2\u00e9"+
		"\u00ea\7k\2\2\u00ea\u00eb\7p\2\2\u00eb\u00ec\7v\2\2\u00ec\u00ed\7q\2\2"+
		"\u00ed\"\3\2\2\2\u00ee\u00ef\7q\2\2\u00ef\u00f0\7p\2\2\u00f0$\3\2\2\2"+
		"\u00f1\u00f2\t\4\2\2\u00f2&\3\2\2\2\u00f3\u00f4\7*\2\2\u00f4(\3\2\2\2"+
		"\u00f5\u00f6\7+\2\2\u00f6*\3\2\2\2\u00f7\u00f8\7y\2\2\u00f8\u00f9\7j\2"+
		"\2\u00f9\u00fa\7g\2\2\u00fa\u00fb\7t\2\2\u00fb\u00fc\7g\2\2\u00fc,\3\2"+
		"\2\2\u00fd\u00fe\7?\2\2\u00fe.\3\2\2\2\u00ff\u0100\7>\2\2\u0100\u0101"+
		"\7@\2\2\u0101\60\3\2\2\2\u0102\u0103\7>\2\2\u0103\62\3\2\2\2\u0104\u0105"+
		"\7@\2\2\u0105\64\3\2\2\2\u0106\u0107\7>\2\2\u0107\u0108\7?\2\2\u0108\66"+
		"\3\2\2\2\u0109\u010a\7@\2\2\u010a\u010b\7?\2\2\u010b8\3\2\2\2\u010c\u010d"+
		"\7c\2\2\u010d\u010e\7p\2\2\u010e\u010f\7f\2\2\u010f:\3\2\2\2\u0110\u0111"+
		"\7q\2\2\u0111\u0112\7t\2\2\u0112<\3\2\2\2\u0113\u0114\7e\2\2\u0114\u0115"+
		"\7j\2\2\u0115\u0116\7c\2\2\u0116\u0117\7t\2\2\u0117>\3\2\2\2\u0118\u0119"+
		"\7k\2\2\u0119\u011a\7p\2\2\u011a\u011b\7v\2\2\u011b@\3\2\2\2\u011c\u011d"+
		"\7h\2\2\u011d\u011e\7n\2\2\u011e\u011f\7q\2\2\u011f\u0120\7c\2\2\u0120"+
		"\u0121\7v\2\2\u0121B\3\2\2\2\u0122\u0123\7w\2\2\u0123\u0124\7p\2\2\u0124"+
		"\u0125\7k\2\2\u0125\u0126\7s\2\2\u0126\u0127\7w\2\2\u0127\u0128\7g\2\2"+
		"\u0128D\3\2\2\2\u0129\u012b\t\5\2\2\u012a\u0129\3\2\2\2\u012a\u012b\3"+
		"\2\2\2\u012b\u012d\3\2\2\2\u012c\u012e\5W,\2\u012d\u012c\3\2\2\2\u012e"+
		"\u012f\3\2\2\2\u012f\u012d\3\2\2\2\u012f\u0130\3\2\2\2\u0130F\3\2\2\2"+
		"\u0131\u0132\5U+\2\u0132H\3\2\2\2\u0133\u0135\t\5\2\2\u0134\u0133\3\2"+
		"\2\2\u0134\u0135\3\2\2\2\u0135\u013b\3\2\2\2\u0136\u0138\5W,\2\u0137\u0136"+
		"\3\2\2\2\u0138\u0139\3\2\2\2\u0139\u0137\3\2\2\2\u0139\u013a\3\2\2\2\u013a"+
		"\u013c\3\2\2\2\u013b\u0137\3\2\2\2\u013b\u013c\3\2\2\2\u013c\u013d\3\2"+
		"\2\2\u013d\u013f\7\60\2\2\u013e\u0140\5W,\2\u013f\u013e\3\2\2\2\u0140"+
		"\u0141\3\2\2\2\u0141\u013f\3\2\2\2\u0141\u0142\3\2\2\2\u0142\u016b\3\2"+
		"\2\2\u0143\u0145\t\5\2\2\u0144\u0143\3\2\2\2\u0144\u0145\3\2\2\2\u0145"+
		"\u0147\3\2\2\2\u0146\u0148\5W,\2\u0147\u0146\3\2\2\2\u0148\u0149\3\2\2"+
		"\2\u0149\u0147\3\2\2\2\u0149\u014a\3\2\2\2\u014a\u014b\3\2\2\2\u014b\u014c"+
		"\7\60\2\2\u014c\u014d\5S*\2\u014d\u016b\3\2\2\2\u014e\u0150\t\5\2\2\u014f"+
		"\u014e\3\2\2\2\u014f\u0150\3\2\2\2\u0150\u0156\3\2\2\2\u0151\u0153\5W"+
		",\2\u0152\u0151\3\2\2\2\u0153\u0154\3\2\2\2\u0154\u0152\3\2\2\2\u0154"+
		"\u0155\3\2\2\2\u0155\u0157\3\2\2\2\u0156\u0152\3\2\2\2\u0156\u0157\3\2"+
		"\2\2\u0157\u0158\3\2\2\2\u0158\u015a\7\60\2\2\u0159\u015b\5W,\2\u015a"+
		"\u0159\3\2\2\2\u015b\u015c\3\2\2\2\u015c\u015a\3\2\2\2\u015c\u015d\3\2"+
		"\2\2\u015d\u015e\3\2\2\2\u015e\u015f\5S*\2\u015f\u016b\3\2\2\2\u0160\u0162"+
		"\t\5\2\2\u0161\u0160\3\2\2\2\u0161\u0162\3\2\2\2\u0162\u0164\3\2\2\2\u0163"+
		"\u0165\5W,\2\u0164\u0163\3\2\2\2\u0165\u0166\3\2\2\2\u0166\u0164\3\2\2"+
		"\2\u0166\u0167\3\2\2\2\u0167\u0168\3\2\2\2\u0168\u0169\5S*\2\u0169\u016b"+
		"\3\2\2\2\u016a\u0134\3\2\2\2\u016a\u0144\3\2\2\2\u016a\u014f\3\2\2\2\u016a"+
		"\u0161\3\2\2\2\u016bJ\3\2\2\2\u016c\u016d\7r\2\2\u016d\u016e\7t\2\2\u016e"+
		"\u016f\7k\2\2\u016f\u0170\7o\2\2\u0170\u0171\7c\2\2\u0171\u0172\7t\2\2"+
		"\u0172\u0173\7{\2\2\u0173\u0174\7\"\2\2\u0174\u0175\7m\2\2\u0175\u0176"+
		"\7g\2\2\u0176\u0177\7{\2\2\u0177L\3\2\2\2\u0178\u0179\7x\2\2\u0179\u017a"+
		"\7c\2\2\u017a\u017b\7n\2\2\u017b\u017c\7w\2\2\u017c\u017d\7g\2\2\u017d"+
		"\u017e\7u\2\2\u017eN\3\2\2\2\u017f\u0180\7.\2\2\u0180P\3\2\2\2\u0181\u0182"+
		"\7=\2\2\u0182R\3\2\2\2\u0183\u0185\7G\2\2\u0184\u0186\t\5\2\2\u0185\u0184"+
		"\3\2\2\2\u0185\u0186\3\2\2\2\u0186\u0188\3\2\2\2\u0187\u0189\5W,\2\u0188"+
		"\u0187\3\2\2\2\u0189\u018a\3\2\2\2\u018a\u0188\3\2\2\2\u018a\u018b\3\2"+
		"\2\2\u018bT\3\2\2\2\u018c\u0190\7$\2\2\u018d\u018f\13\2\2\2\u018e\u018d"+
		"\3\2\2\2\u018f\u0192\3\2\2\2\u0190\u0191\3\2\2\2\u0190\u018e\3\2\2\2\u0191"+
		"\u0193\3\2\2\2\u0192\u0190\3\2\2\2\u0193\u0194\7$\2\2\u0194V\3\2\2\2\u0195"+
		"\u0196\t\6\2\2\u0196X\3\2\2\2\u0197\u019b\5[.\2\u0198\u019b\5]/\2\u0199"+
		"\u019b\5_\60\2\u019a\u0197\3\2\2\2\u019a\u0198\3\2\2\2\u019a\u0199\3\2"+
		"\2\2\u019bZ\3\2\2\2\u019c\u019e\t\7\2\2\u019d\u019c\3\2\2\2\u019e\u019f"+
		"\3\2\2\2\u019f\u019d\3\2\2\2\u019f\u01a0\3\2\2\2\u01a0\u01a4\3\2\2\2\u01a1"+
		"\u01a3\t\b\2\2\u01a2\u01a1\3\2\2\2\u01a3\u01a6\3\2\2\2\u01a4\u01a2\3\2"+
		"\2\2\u01a4\u01a5\3\2\2\2\u01a5\\\3\2\2\2\u01a6\u01a4\3\2\2\2\u01a7\u01a9"+
		"\t\7\2\2\u01a8\u01a7\3\2\2\2\u01a9\u01aa\3\2\2\2\u01aa\u01a8\3\2\2\2\u01aa"+
		"\u01ab\3\2\2\2\u01ab\u01af\3\2\2\2\u01ac\u01ae\t\b\2\2\u01ad\u01ac\3\2"+
		"\2\2\u01ae\u01b1\3\2\2\2\u01af\u01ad\3\2\2\2\u01af\u01b0\3\2\2\2\u01b0"+
		"^\3\2\2\2\u01b1\u01af\3\2\2\2\u01b2\u01b4\t\7\2\2\u01b3\u01b2\3\2\2\2"+
		"\u01b4\u01b5\3\2\2\2\u01b5\u01b3\3\2\2\2\u01b5\u01b6\3\2\2\2\u01b6\u01ba"+
		"\3\2\2\2\u01b7\u01b9\t\b\2\2\u01b8\u01b7\3\2\2\2\u01b9\u01bc\3\2\2\2\u01ba"+
		"\u01b8\3\2\2\2\u01ba\u01bb\3\2\2\2\u01bb`\3\2\2\2\u01bc\u01ba\3\2\2\2"+
		"\u01bd\u01be\13\2\2\2\u01be\u01bf\3\2\2\2\u01bf\u01c0\b\61\4\2\u01c0b"+
		"\3\2\2\2&\2fq~\u008a\u008f\u0093\u0097\u009d\u00a1\u00a3\u012a\u012f\u0134"+
		"\u0139\u013b\u0141\u0144\u0149\u014f\u0154\u0156\u015c\u0161\u0166\u016a"+
		"\u0185\u018a\u0190\u019a\u019f\u01a4\u01aa\u01af\u01b5\u01ba\5\2\3\2\2"+
		"\5\2\2\4\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}