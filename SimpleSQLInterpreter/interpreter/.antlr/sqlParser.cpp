
// Generated from d:\work\personal\2020DB\miniSQL\SimpleSQLInterpreter\interpreter\sqlParser.g4 by ANTLR 4.7.1



#include "sqlParser.h"


using namespace antlrcpp;
using namespace antlr4;

sqlParser::sqlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

sqlParser::~sqlParser() {
  delete _interpreter;
}

std::string sqlParser::getGrammarFileName() const {
  return "sqlParser.g4";
}

const std::vector<std::string>& sqlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& sqlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

sqlParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::RootContext::EOF() {
  return getToken(sqlParser::EOF, 0);
}

sqlParser::SqlStatementsContext* sqlParser::RootContext::sqlStatements() {
  return getRuleContext<sqlParser::SqlStatementsContext>(0);
}


size_t sqlParser::RootContext::getRuleIndex() const {
  return sqlParser::RuleRoot;
}


sqlParser::RootContext* sqlParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, sqlParser::RuleRoot);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(61);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << sqlParser::SELECT)
      | (1ULL << sqlParser::INSERT)
      | (1ULL << sqlParser::DELETE)
      | (1ULL << sqlParser::DROP)
      | (1ULL << sqlParser::CREATE)
      | (1ULL << sqlParser::QUIT)
      | (1ULL << sqlParser::EXECFILE)
      | (1ULL << sqlParser::SEMICOLON))) != 0)) {
      setState(60);
      sqlStatements();
    }
    setState(63);
    match(sqlParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SqlStatementsContext ------------------------------------------------------------------

sqlParser::SqlStatementsContext::SqlStatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sqlParser::SqlStatementContext *> sqlParser::SqlStatementsContext::sqlStatement() {
  return getRuleContexts<sqlParser::SqlStatementContext>();
}

sqlParser::SqlStatementContext* sqlParser::SqlStatementsContext::sqlStatement(size_t i) {
  return getRuleContext<sqlParser::SqlStatementContext>(i);
}

std::vector<sqlParser::EmptyStatementContext *> sqlParser::SqlStatementsContext::emptyStatement() {
  return getRuleContexts<sqlParser::EmptyStatementContext>();
}

sqlParser::EmptyStatementContext* sqlParser::SqlStatementsContext::emptyStatement(size_t i) {
  return getRuleContext<sqlParser::EmptyStatementContext>(i);
}

std::vector<tree::TerminalNode *> sqlParser::SqlStatementsContext::SEMICOLON() {
  return getTokens(sqlParser::SEMICOLON);
}

tree::TerminalNode* sqlParser::SqlStatementsContext::SEMICOLON(size_t i) {
  return getToken(sqlParser::SEMICOLON, i);
}


size_t sqlParser::SqlStatementsContext::getRuleIndex() const {
  return sqlParser::RuleSqlStatements;
}


sqlParser::SqlStatementsContext* sqlParser::sqlStatements() {
  SqlStatementsContext *_localctx = _tracker.createInstance<SqlStatementsContext>(_ctx, getState());
  enterRule(_localctx, 2, sqlParser::RuleSqlStatements);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(71);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(69);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case sqlParser::SELECT:
          case sqlParser::INSERT:
          case sqlParser::DELETE:
          case sqlParser::DROP:
          case sqlParser::CREATE:
          case sqlParser::QUIT:
          case sqlParser::EXECFILE: {
            setState(65);
            sqlStatement();
            setState(66);
            match(sqlParser::SEMICOLON);
            break;
          }

          case sqlParser::SEMICOLON: {
            setState(68);
            emptyStatement();
            break;
          }

        default:
          throw NoViableAltException(this);
        } 
      }
      setState(73);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(78);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sqlParser::SELECT:
      case sqlParser::INSERT:
      case sqlParser::DELETE:
      case sqlParser::DROP:
      case sqlParser::CREATE:
      case sqlParser::QUIT:
      case sqlParser::EXECFILE: {
        setState(74);
        sqlStatement();

        setState(75);
        match(sqlParser::SEMICOLON);
        break;
      }

      case sqlParser::SEMICOLON: {
        setState(77);
        emptyStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SqlStatementContext ------------------------------------------------------------------

sqlParser::SqlStatementContext::SqlStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sqlParser::SelectQueryContext* sqlParser::SqlStatementContext::selectQuery() {
  return getRuleContext<sqlParser::SelectQueryContext>(0);
}

sqlParser::DropIndexQueryContext* sqlParser::SqlStatementContext::dropIndexQuery() {
  return getRuleContext<sqlParser::DropIndexQueryContext>(0);
}

sqlParser::DropTableQueryContext* sqlParser::SqlStatementContext::dropTableQuery() {
  return getRuleContext<sqlParser::DropTableQueryContext>(0);
}

sqlParser::CreateIndexQueryContext* sqlParser::SqlStatementContext::createIndexQuery() {
  return getRuleContext<sqlParser::CreateIndexQueryContext>(0);
}

sqlParser::CreateTableQueryContext* sqlParser::SqlStatementContext::createTableQuery() {
  return getRuleContext<sqlParser::CreateTableQueryContext>(0);
}

sqlParser::InsertQueryContext* sqlParser::SqlStatementContext::insertQuery() {
  return getRuleContext<sqlParser::InsertQueryContext>(0);
}

sqlParser::DeleteQueryContext* sqlParser::SqlStatementContext::deleteQuery() {
  return getRuleContext<sqlParser::DeleteQueryContext>(0);
}

sqlParser::QuitStatementContext* sqlParser::SqlStatementContext::quitStatement() {
  return getRuleContext<sqlParser::QuitStatementContext>(0);
}

sqlParser::ExecfileStatementContext* sqlParser::SqlStatementContext::execfileStatement() {
  return getRuleContext<sqlParser::ExecfileStatementContext>(0);
}


size_t sqlParser::SqlStatementContext::getRuleIndex() const {
  return sqlParser::RuleSqlStatement;
}


sqlParser::SqlStatementContext* sqlParser::sqlStatement() {
  SqlStatementContext *_localctx = _tracker.createInstance<SqlStatementContext>(_ctx, getState());
  enterRule(_localctx, 4, sqlParser::RuleSqlStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(89);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(80);
      selectQuery();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(81);
      dropIndexQuery();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(82);
      dropTableQuery();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(83);
      createIndexQuery();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(84);
      createTableQuery();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(85);
      insertQuery();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(86);
      deleteQuery();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(87);
      quitStatement();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(88);
      execfileStatement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

sqlParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::EmptyStatementContext::SEMICOLON() {
  return getToken(sqlParser::SEMICOLON, 0);
}


size_t sqlParser::EmptyStatementContext::getRuleIndex() const {
  return sqlParser::RuleEmptyStatement;
}


sqlParser::EmptyStatementContext* sqlParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 6, sqlParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    match(sqlParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectQueryContext ------------------------------------------------------------------

sqlParser::SelectQueryContext::SelectQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::SelectQueryContext::SELECT() {
  return getToken(sqlParser::SELECT, 0);
}

tree::TerminalNode* sqlParser::SelectQueryContext::WILDCARD() {
  return getToken(sqlParser::WILDCARD, 0);
}

tree::TerminalNode* sqlParser::SelectQueryContext::FROM() {
  return getToken(sqlParser::FROM, 0);
}

sqlParser::SelectTargetContext* sqlParser::SelectQueryContext::selectTarget() {
  return getRuleContext<sqlParser::SelectTargetContext>(0);
}

sqlParser::OptionalWhereClauseContext* sqlParser::SelectQueryContext::optionalWhereClause() {
  return getRuleContext<sqlParser::OptionalWhereClauseContext>(0);
}


size_t sqlParser::SelectQueryContext::getRuleIndex() const {
  return sqlParser::RuleSelectQuery;
}


sqlParser::SelectQueryContext* sqlParser::selectQuery() {
  SelectQueryContext *_localctx = _tracker.createInstance<SelectQueryContext>(_ctx, getState());
  enterRule(_localctx, 8, sqlParser::RuleSelectQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(93);
    match(sqlParser::SELECT);
    setState(94);
    match(sqlParser::WILDCARD);
    setState(95);
    match(sqlParser::FROM);
    setState(96);
    selectTarget();
    setState(97);
    optionalWhereClause();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectTargetContext ------------------------------------------------------------------

sqlParser::SelectTargetContext::SelectTargetContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sqlParser::TableNameContext* sqlParser::SelectTargetContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}


size_t sqlParser::SelectTargetContext::getRuleIndex() const {
  return sqlParser::RuleSelectTarget;
}


sqlParser::SelectTargetContext* sqlParser::selectTarget() {
  SelectTargetContext *_localctx = _tracker.createInstance<SelectTargetContext>(_ctx, getState());
  enterRule(_localctx, 10, sqlParser::RuleSelectTarget);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    tableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OptionalWhereClauseContext ------------------------------------------------------------------

sqlParser::OptionalWhereClauseContext::OptionalWhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sqlParser::WhereClauseContext* sqlParser::OptionalWhereClauseContext::whereClause() {
  return getRuleContext<sqlParser::WhereClauseContext>(0);
}


size_t sqlParser::OptionalWhereClauseContext::getRuleIndex() const {
  return sqlParser::RuleOptionalWhereClause;
}


sqlParser::OptionalWhereClauseContext* sqlParser::optionalWhereClause() {
  OptionalWhereClauseContext *_localctx = _tracker.createInstance<OptionalWhereClauseContext>(_ctx, getState());
  enterRule(_localctx, 12, sqlParser::RuleOptionalWhereClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(103);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sqlParser::WHERE: {
        enterOuterAlt(_localctx, 1);
        setState(101);
        whereClause();
        break;
      }

      case sqlParser::SEMICOLON: {
        enterOuterAlt(_localctx, 2);

        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereClauseContext ------------------------------------------------------------------

sqlParser::WhereClauseContext::WhereClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::WhereClauseContext::WHERE() {
  return getToken(sqlParser::WHERE, 0);
}

sqlParser::WhereConditionsContext* sqlParser::WhereClauseContext::whereConditions() {
  return getRuleContext<sqlParser::WhereConditionsContext>(0);
}


size_t sqlParser::WhereClauseContext::getRuleIndex() const {
  return sqlParser::RuleWhereClause;
}


sqlParser::WhereClauseContext* sqlParser::whereClause() {
  WhereClauseContext *_localctx = _tracker.createInstance<WhereClauseContext>(_ctx, getState());
  enterRule(_localctx, 14, sqlParser::RuleWhereClause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(105);
    match(sqlParser::WHERE);
    setState(106);
    whereConditions();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereConditionsContext ------------------------------------------------------------------

sqlParser::WhereConditionsContext::WhereConditionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sqlParser::WhereConditionContext *> sqlParser::WhereConditionsContext::whereCondition() {
  return getRuleContexts<sqlParser::WhereConditionContext>();
}

sqlParser::WhereConditionContext* sqlParser::WhereConditionsContext::whereCondition(size_t i) {
  return getRuleContext<sqlParser::WhereConditionContext>(i);
}

std::vector<sqlParser::WhereOPContext *> sqlParser::WhereConditionsContext::whereOP() {
  return getRuleContexts<sqlParser::WhereOPContext>();
}

sqlParser::WhereOPContext* sqlParser::WhereConditionsContext::whereOP(size_t i) {
  return getRuleContext<sqlParser::WhereOPContext>(i);
}


size_t sqlParser::WhereConditionsContext::getRuleIndex() const {
  return sqlParser::RuleWhereConditions;
}


sqlParser::WhereConditionsContext* sqlParser::whereConditions() {
  WhereConditionsContext *_localctx = _tracker.createInstance<WhereConditionsContext>(_ctx, getState());
  enterRule(_localctx, 16, sqlParser::RuleWhereConditions);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    whereCondition();
    setState(114);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sqlParser::AND) {
      setState(109);
      whereOP();
      setState(110);
      whereCondition();
      setState(116);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereConditionContext ------------------------------------------------------------------

sqlParser::WhereConditionContext::WhereConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

sqlParser::ColumnNameContext* sqlParser::WhereConditionContext::columnName() {
  return getRuleContext<sqlParser::ColumnNameContext>(0);
}

sqlParser::OpContext* sqlParser::WhereConditionContext::op() {
  return getRuleContext<sqlParser::OpContext>(0);
}

sqlParser::LiteralContext* sqlParser::WhereConditionContext::literal() {
  return getRuleContext<sqlParser::LiteralContext>(0);
}


size_t sqlParser::WhereConditionContext::getRuleIndex() const {
  return sqlParser::RuleWhereCondition;
}


sqlParser::WhereConditionContext* sqlParser::whereCondition() {
  WhereConditionContext *_localctx = _tracker.createInstance<WhereConditionContext>(_ctx, getState());
  enterRule(_localctx, 18, sqlParser::RuleWhereCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(117);
    columnName();
    setState(118);
    op();
    setState(119);
    literal();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhereOPContext ------------------------------------------------------------------

sqlParser::WhereOPContext::WhereOPContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::WhereOPContext::AND() {
  return getToken(sqlParser::AND, 0);
}


size_t sqlParser::WhereOPContext::getRuleIndex() const {
  return sqlParser::RuleWhereOP;
}


sqlParser::WhereOPContext* sqlParser::whereOP() {
  WhereOPContext *_localctx = _tracker.createInstance<WhereOPContext>(_ctx, getState());
  enterRule(_localctx, 20, sqlParser::RuleWhereOP);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(121);
    match(sqlParser::AND);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropIndexQueryContext ------------------------------------------------------------------

sqlParser::DropIndexQueryContext::DropIndexQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::DropIndexQueryContext::DROP() {
  return getToken(sqlParser::DROP, 0);
}

tree::TerminalNode* sqlParser::DropIndexQueryContext::INDEX() {
  return getToken(sqlParser::INDEX, 0);
}

sqlParser::IndexNameContext* sqlParser::DropIndexQueryContext::indexName() {
  return getRuleContext<sqlParser::IndexNameContext>(0);
}


size_t sqlParser::DropIndexQueryContext::getRuleIndex() const {
  return sqlParser::RuleDropIndexQuery;
}


sqlParser::DropIndexQueryContext* sqlParser::dropIndexQuery() {
  DropIndexQueryContext *_localctx = _tracker.createInstance<DropIndexQueryContext>(_ctx, getState());
  enterRule(_localctx, 22, sqlParser::RuleDropIndexQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    match(sqlParser::DROP);
    setState(124);
    match(sqlParser::INDEX);
    setState(125);
    indexName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DropTableQueryContext ------------------------------------------------------------------

sqlParser::DropTableQueryContext::DropTableQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::DropTableQueryContext::DROP() {
  return getToken(sqlParser::DROP, 0);
}

tree::TerminalNode* sqlParser::DropTableQueryContext::TABLE() {
  return getToken(sqlParser::TABLE, 0);
}

sqlParser::TableNameContext* sqlParser::DropTableQueryContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}


size_t sqlParser::DropTableQueryContext::getRuleIndex() const {
  return sqlParser::RuleDropTableQuery;
}


sqlParser::DropTableQueryContext* sqlParser::dropTableQuery() {
  DropTableQueryContext *_localctx = _tracker.createInstance<DropTableQueryContext>(_ctx, getState());
  enterRule(_localctx, 24, sqlParser::RuleDropTableQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(127);
    match(sqlParser::DROP);
    setState(128);
    match(sqlParser::TABLE);
    setState(129);
    tableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateIndexQueryContext ------------------------------------------------------------------

sqlParser::CreateIndexQueryContext::CreateIndexQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::CreateIndexQueryContext::CREATE() {
  return getToken(sqlParser::CREATE, 0);
}

tree::TerminalNode* sqlParser::CreateIndexQueryContext::INDEX() {
  return getToken(sqlParser::INDEX, 0);
}

sqlParser::IndexNameContext* sqlParser::CreateIndexQueryContext::indexName() {
  return getRuleContext<sqlParser::IndexNameContext>(0);
}

tree::TerminalNode* sqlParser::CreateIndexQueryContext::ON() {
  return getToken(sqlParser::ON, 0);
}

sqlParser::TableNameContext* sqlParser::CreateIndexQueryContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}

tree::TerminalNode* sqlParser::CreateIndexQueryContext::OPEN_BRACKET() {
  return getToken(sqlParser::OPEN_BRACKET, 0);
}

sqlParser::ColumnNameContext* sqlParser::CreateIndexQueryContext::columnName() {
  return getRuleContext<sqlParser::ColumnNameContext>(0);
}

tree::TerminalNode* sqlParser::CreateIndexQueryContext::CLOSE_BRACKET() {
  return getToken(sqlParser::CLOSE_BRACKET, 0);
}


size_t sqlParser::CreateIndexQueryContext::getRuleIndex() const {
  return sqlParser::RuleCreateIndexQuery;
}


sqlParser::CreateIndexQueryContext* sqlParser::createIndexQuery() {
  CreateIndexQueryContext *_localctx = _tracker.createInstance<CreateIndexQueryContext>(_ctx, getState());
  enterRule(_localctx, 26, sqlParser::RuleCreateIndexQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(131);
    match(sqlParser::CREATE);
    setState(132);
    match(sqlParser::INDEX);
    setState(133);
    indexName();
    setState(134);
    match(sqlParser::ON);
    setState(135);
    tableName();
    setState(136);
    match(sqlParser::OPEN_BRACKET);
    setState(137);
    columnName();
    setState(138);
    match(sqlParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CreateTableQueryContext ------------------------------------------------------------------

sqlParser::CreateTableQueryContext::CreateTableQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::CreateTableQueryContext::CREATE() {
  return getToken(sqlParser::CREATE, 0);
}

tree::TerminalNode* sqlParser::CreateTableQueryContext::TABLE() {
  return getToken(sqlParser::TABLE, 0);
}

sqlParser::TableNameContext* sqlParser::CreateTableQueryContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}

tree::TerminalNode* sqlParser::CreateTableQueryContext::OPEN_BRACKET() {
  return getToken(sqlParser::OPEN_BRACKET, 0);
}

sqlParser::ColumnDefinitionsContext* sqlParser::CreateTableQueryContext::columnDefinitions() {
  return getRuleContext<sqlParser::ColumnDefinitionsContext>(0);
}

sqlParser::PrimaryKeyDefinitionContext* sqlParser::CreateTableQueryContext::primaryKeyDefinition() {
  return getRuleContext<sqlParser::PrimaryKeyDefinitionContext>(0);
}

tree::TerminalNode* sqlParser::CreateTableQueryContext::CLOSE_BRACKET() {
  return getToken(sqlParser::CLOSE_BRACKET, 0);
}


size_t sqlParser::CreateTableQueryContext::getRuleIndex() const {
  return sqlParser::RuleCreateTableQuery;
}


sqlParser::CreateTableQueryContext* sqlParser::createTableQuery() {
  CreateTableQueryContext *_localctx = _tracker.createInstance<CreateTableQueryContext>(_ctx, getState());
  enterRule(_localctx, 28, sqlParser::RuleCreateTableQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(sqlParser::CREATE);
    setState(141);
    match(sqlParser::TABLE);
    setState(142);
    tableName();
    setState(143);
    match(sqlParser::OPEN_BRACKET);
    setState(144);
    columnDefinitions();
    setState(145);
    primaryKeyDefinition();
    setState(146);
    match(sqlParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnDefinitionsContext ------------------------------------------------------------------

sqlParser::ColumnDefinitionsContext::ColumnDefinitionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<sqlParser::ColumnDefinitionContext *> sqlParser::ColumnDefinitionsContext::columnDefinition() {
  return getRuleContexts<sqlParser::ColumnDefinitionContext>();
}

sqlParser::ColumnDefinitionContext* sqlParser::ColumnDefinitionsContext::columnDefinition(size_t i) {
  return getRuleContext<sqlParser::ColumnDefinitionContext>(i);
}


size_t sqlParser::ColumnDefinitionsContext::getRuleIndex() const {
  return sqlParser::RuleColumnDefinitions;
}


sqlParser::ColumnDefinitionsContext* sqlParser::columnDefinitions() {
  ColumnDefinitionsContext *_localctx = _tracker.createInstance<ColumnDefinitionsContext>(_ctx, getState());
  enterRule(_localctx, 30, sqlParser::RuleColumnDefinitions);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(148);
      columnDefinition();
      setState(151); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == sqlParser::TOKEN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnDefinitionContext ------------------------------------------------------------------

sqlParser::ColumnDefinitionContext::ColumnDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t sqlParser::ColumnDefinitionContext::getRuleIndex() const {
  return sqlParser::RuleColumnDefinition;
}

void sqlParser::ColumnDefinitionContext::copyFrom(ColumnDefinitionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NonUniqueColumnDefinitionContext ------------------------------------------------------------------

sqlParser::ColumnNameContext* sqlParser::NonUniqueColumnDefinitionContext::columnName() {
  return getRuleContext<sqlParser::ColumnNameContext>(0);
}

sqlParser::TypeContext* sqlParser::NonUniqueColumnDefinitionContext::type() {
  return getRuleContext<sqlParser::TypeContext>(0);
}

tree::TerminalNode* sqlParser::NonUniqueColumnDefinitionContext::COMMA() {
  return getToken(sqlParser::COMMA, 0);
}

sqlParser::NonUniqueColumnDefinitionContext::NonUniqueColumnDefinitionContext(ColumnDefinitionContext *ctx) { copyFrom(ctx); }


//----------------- UniqueColumnDefinitionContext ------------------------------------------------------------------

sqlParser::ColumnNameContext* sqlParser::UniqueColumnDefinitionContext::columnName() {
  return getRuleContext<sqlParser::ColumnNameContext>(0);
}

sqlParser::TypeContext* sqlParser::UniqueColumnDefinitionContext::type() {
  return getRuleContext<sqlParser::TypeContext>(0);
}

tree::TerminalNode* sqlParser::UniqueColumnDefinitionContext::UNIQUE() {
  return getToken(sqlParser::UNIQUE, 0);
}

tree::TerminalNode* sqlParser::UniqueColumnDefinitionContext::COMMA() {
  return getToken(sqlParser::COMMA, 0);
}

sqlParser::UniqueColumnDefinitionContext::UniqueColumnDefinitionContext(ColumnDefinitionContext *ctx) { copyFrom(ctx); }


sqlParser::ColumnDefinitionContext* sqlParser::columnDefinition() {
  ColumnDefinitionContext *_localctx = _tracker.createInstance<ColumnDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 32, sqlParser::RuleColumnDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<ColumnDefinitionContext *>(_tracker.createInstance<sqlParser::NonUniqueColumnDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(153);
      columnName();
      setState(154);
      type();
      setState(155);
      match(sqlParser::COMMA);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<ColumnDefinitionContext *>(_tracker.createInstance<sqlParser::UniqueColumnDefinitionContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(157);
      columnName();
      setState(158);
      type();
      setState(159);
      match(sqlParser::UNIQUE);
      setState(160);
      match(sqlParser::COMMA);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryKeyDefinitionContext ------------------------------------------------------------------

sqlParser::PrimaryKeyDefinitionContext::PrimaryKeyDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::PrimaryKeyDefinitionContext::PRIMARY_KEY() {
  return getToken(sqlParser::PRIMARY_KEY, 0);
}

tree::TerminalNode* sqlParser::PrimaryKeyDefinitionContext::OPEN_BRACKET() {
  return getToken(sqlParser::OPEN_BRACKET, 0);
}

sqlParser::ColumnNameContext* sqlParser::PrimaryKeyDefinitionContext::columnName() {
  return getRuleContext<sqlParser::ColumnNameContext>(0);
}

tree::TerminalNode* sqlParser::PrimaryKeyDefinitionContext::CLOSE_BRACKET() {
  return getToken(sqlParser::CLOSE_BRACKET, 0);
}


size_t sqlParser::PrimaryKeyDefinitionContext::getRuleIndex() const {
  return sqlParser::RulePrimaryKeyDefinition;
}


sqlParser::PrimaryKeyDefinitionContext* sqlParser::primaryKeyDefinition() {
  PrimaryKeyDefinitionContext *_localctx = _tracker.createInstance<PrimaryKeyDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 34, sqlParser::RulePrimaryKeyDefinition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(sqlParser::PRIMARY_KEY);
    setState(165);
    match(sqlParser::OPEN_BRACKET);
    setState(166);
    columnName();
    setState(167);
    match(sqlParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InsertQueryContext ------------------------------------------------------------------

sqlParser::InsertQueryContext::InsertQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::InsertQueryContext::INSERT() {
  return getToken(sqlParser::INSERT, 0);
}

tree::TerminalNode* sqlParser::InsertQueryContext::INTO() {
  return getToken(sqlParser::INTO, 0);
}

sqlParser::TableNameContext* sqlParser::InsertQueryContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}

tree::TerminalNode* sqlParser::InsertQueryContext::VALUES() {
  return getToken(sqlParser::VALUES, 0);
}

sqlParser::LiteralValuesContext* sqlParser::InsertQueryContext::literalValues() {
  return getRuleContext<sqlParser::LiteralValuesContext>(0);
}


size_t sqlParser::InsertQueryContext::getRuleIndex() const {
  return sqlParser::RuleInsertQuery;
}


sqlParser::InsertQueryContext* sqlParser::insertQuery() {
  InsertQueryContext *_localctx = _tracker.createInstance<InsertQueryContext>(_ctx, getState());
  enterRule(_localctx, 36, sqlParser::RuleInsertQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(169);
    match(sqlParser::INSERT);
    setState(170);
    match(sqlParser::INTO);
    setState(171);
    tableName();
    setState(172);
    match(sqlParser::VALUES);
    setState(173);
    literalValues();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValuesContext ------------------------------------------------------------------

sqlParser::LiteralValuesContext::LiteralValuesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::LiteralValuesContext::OPEN_BRACKET() {
  return getToken(sqlParser::OPEN_BRACKET, 0);
}

std::vector<sqlParser::LiteralContext *> sqlParser::LiteralValuesContext::literal() {
  return getRuleContexts<sqlParser::LiteralContext>();
}

sqlParser::LiteralContext* sqlParser::LiteralValuesContext::literal(size_t i) {
  return getRuleContext<sqlParser::LiteralContext>(i);
}

tree::TerminalNode* sqlParser::LiteralValuesContext::CLOSE_BRACKET() {
  return getToken(sqlParser::CLOSE_BRACKET, 0);
}

std::vector<tree::TerminalNode *> sqlParser::LiteralValuesContext::COMMA() {
  return getTokens(sqlParser::COMMA);
}

tree::TerminalNode* sqlParser::LiteralValuesContext::COMMA(size_t i) {
  return getToken(sqlParser::COMMA, i);
}


size_t sqlParser::LiteralValuesContext::getRuleIndex() const {
  return sqlParser::RuleLiteralValues;
}


sqlParser::LiteralValuesContext* sqlParser::literalValues() {
  LiteralValuesContext *_localctx = _tracker.createInstance<LiteralValuesContext>(_ctx, getState());
  enterRule(_localctx, 38, sqlParser::RuleLiteralValues);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    match(sqlParser::OPEN_BRACKET);
    setState(176);
    literal();
    setState(181);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == sqlParser::COMMA) {
      setState(177);
      match(sqlParser::COMMA);
      setState(178);
      literal();
      setState(183);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(184);
    match(sqlParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeleteQueryContext ------------------------------------------------------------------

sqlParser::DeleteQueryContext::DeleteQueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::DeleteQueryContext::DELETE() {
  return getToken(sqlParser::DELETE, 0);
}

tree::TerminalNode* sqlParser::DeleteQueryContext::FROM() {
  return getToken(sqlParser::FROM, 0);
}

sqlParser::TableNameContext* sqlParser::DeleteQueryContext::tableName() {
  return getRuleContext<sqlParser::TableNameContext>(0);
}

sqlParser::OptionalWhereClauseContext* sqlParser::DeleteQueryContext::optionalWhereClause() {
  return getRuleContext<sqlParser::OptionalWhereClauseContext>(0);
}


size_t sqlParser::DeleteQueryContext::getRuleIndex() const {
  return sqlParser::RuleDeleteQuery;
}


sqlParser::DeleteQueryContext* sqlParser::deleteQuery() {
  DeleteQueryContext *_localctx = _tracker.createInstance<DeleteQueryContext>(_ctx, getState());
  enterRule(_localctx, 40, sqlParser::RuleDeleteQuery);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(sqlParser::DELETE);
    setState(187);
    match(sqlParser::FROM);
    setState(188);
    tableName();
    setState(189);
    optionalWhereClause();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QuitStatementContext ------------------------------------------------------------------

sqlParser::QuitStatementContext::QuitStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::QuitStatementContext::QUIT() {
  return getToken(sqlParser::QUIT, 0);
}


size_t sqlParser::QuitStatementContext::getRuleIndex() const {
  return sqlParser::RuleQuitStatement;
}


sqlParser::QuitStatementContext* sqlParser::quitStatement() {
  QuitStatementContext *_localctx = _tracker.createInstance<QuitStatementContext>(_ctx, getState());
  enterRule(_localctx, 42, sqlParser::RuleQuitStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(191);
    match(sqlParser::QUIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecfileStatementContext ------------------------------------------------------------------

sqlParser::ExecfileStatementContext::ExecfileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::ExecfileStatementContext::EXECFILE() {
  return getToken(sqlParser::EXECFILE, 0);
}

tree::TerminalNode* sqlParser::ExecfileStatementContext::STRING_LITERAL() {
  return getToken(sqlParser::STRING_LITERAL, 0);
}


size_t sqlParser::ExecfileStatementContext::getRuleIndex() const {
  return sqlParser::RuleExecfileStatement;
}


sqlParser::ExecfileStatementContext* sqlParser::execfileStatement() {
  ExecfileStatementContext *_localctx = _tracker.createInstance<ExecfileStatementContext>(_ctx, getState());
  enterRule(_localctx, 44, sqlParser::RuleExecfileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193);
    match(sqlParser::EXECFILE);
    setState(194);
    match(sqlParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TableNameContext ------------------------------------------------------------------

sqlParser::TableNameContext::TableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::TableNameContext::TOKEN() {
  return getToken(sqlParser::TOKEN, 0);
}


size_t sqlParser::TableNameContext::getRuleIndex() const {
  return sqlParser::RuleTableName;
}


sqlParser::TableNameContext* sqlParser::tableName() {
  TableNameContext *_localctx = _tracker.createInstance<TableNameContext>(_ctx, getState());
  enterRule(_localctx, 46, sqlParser::RuleTableName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    match(sqlParser::TOKEN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColumnNameContext ------------------------------------------------------------------

sqlParser::ColumnNameContext::ColumnNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::ColumnNameContext::TOKEN() {
  return getToken(sqlParser::TOKEN, 0);
}


size_t sqlParser::ColumnNameContext::getRuleIndex() const {
  return sqlParser::RuleColumnName;
}


sqlParser::ColumnNameContext* sqlParser::columnName() {
  ColumnNameContext *_localctx = _tracker.createInstance<ColumnNameContext>(_ctx, getState());
  enterRule(_localctx, 48, sqlParser::RuleColumnName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    match(sqlParser::TOKEN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexNameContext ------------------------------------------------------------------

sqlParser::IndexNameContext::IndexNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::IndexNameContext::TOKEN() {
  return getToken(sqlParser::TOKEN, 0);
}


size_t sqlParser::IndexNameContext::getRuleIndex() const {
  return sqlParser::RuleIndexName;
}


sqlParser::IndexNameContext* sqlParser::indexName() {
  IndexNameContext *_localctx = _tracker.createInstance<IndexNameContext>(_ctx, getState());
  enterRule(_localctx, 50, sqlParser::RuleIndexName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    match(sqlParser::TOKEN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

sqlParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::LiteralContext::DECIMAL_LITERAL() {
  return getToken(sqlParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* sqlParser::LiteralContext::STRING_LITERAL() {
  return getToken(sqlParser::STRING_LITERAL, 0);
}

tree::TerminalNode* sqlParser::LiteralContext::REAL_LITERAL() {
  return getToken(sqlParser::REAL_LITERAL, 0);
}


size_t sqlParser::LiteralContext::getRuleIndex() const {
  return sqlParser::RuleLiteral;
}


sqlParser::LiteralContext* sqlParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 52, sqlParser::RuleLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(202);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << sqlParser::DECIMAL_LITERAL)
      | (1ULL << sqlParser::STRING_LITERAL)
      | (1ULL << sqlParser::REAL_LITERAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OpContext ------------------------------------------------------------------

sqlParser::OpContext::OpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t sqlParser::OpContext::getRuleIndex() const {
  return sqlParser::RuleOp;
}

void sqlParser::OpContext::copyFrom(OpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- OpGTEContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpGTEContext::GREATER_EQUAL() {
  return getToken(sqlParser::GREATER_EQUAL, 0);
}

sqlParser::OpGTEContext::OpGTEContext(OpContext *ctx) { copyFrom(ctx); }


//----------------- OpEQContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpEQContext::EQUAL() {
  return getToken(sqlParser::EQUAL, 0);
}

sqlParser::OpEQContext::OpEQContext(OpContext *ctx) { copyFrom(ctx); }


//----------------- OpNEQContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpNEQContext::NOT_EQUAL() {
  return getToken(sqlParser::NOT_EQUAL, 0);
}

sqlParser::OpNEQContext::OpNEQContext(OpContext *ctx) { copyFrom(ctx); }


//----------------- OpGTContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpGTContext::GREATER() {
  return getToken(sqlParser::GREATER, 0);
}

sqlParser::OpGTContext::OpGTContext(OpContext *ctx) { copyFrom(ctx); }


//----------------- OpLTEContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpLTEContext::SMALLER_EQUAL() {
  return getToken(sqlParser::SMALLER_EQUAL, 0);
}

sqlParser::OpLTEContext::OpLTEContext(OpContext *ctx) { copyFrom(ctx); }


//----------------- OpLTContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::OpLTContext::SMALLER() {
  return getToken(sqlParser::SMALLER, 0);
}

sqlParser::OpLTContext::OpLTContext(OpContext *ctx) { copyFrom(ctx); }


sqlParser::OpContext* sqlParser::op() {
  OpContext *_localctx = _tracker.createInstance<OpContext>(_ctx, getState());
  enterRule(_localctx, 54, sqlParser::RuleOp);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sqlParser::EQUAL: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpEQContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(204);
        match(sqlParser::EQUAL);
        break;
      }

      case sqlParser::NOT_EQUAL: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpNEQContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(205);
        match(sqlParser::NOT_EQUAL);
        break;
      }

      case sqlParser::SMALLER: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpLTContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(206);
        match(sqlParser::SMALLER);
        break;
      }

      case sqlParser::SMALLER_EQUAL: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpLTEContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(207);
        match(sqlParser::SMALLER_EQUAL);
        break;
      }

      case sqlParser::GREATER: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpGTContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(208);
        match(sqlParser::GREATER);
        break;
      }

      case sqlParser::GREATER_EQUAL: {
        _localctx = dynamic_cast<OpContext *>(_tracker.createInstance<sqlParser::OpGTEContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(209);
        match(sqlParser::GREATER_EQUAL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

sqlParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t sqlParser::TypeContext::getRuleIndex() const {
  return sqlParser::RuleType;
}

void sqlParser::TypeContext::copyFrom(TypeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IntTypeDefContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::IntTypeDefContext::INT() {
  return getToken(sqlParser::INT, 0);
}

sqlParser::IntTypeDefContext::IntTypeDefContext(TypeContext *ctx) { copyFrom(ctx); }


//----------------- CharTypeDefContext ------------------------------------------------------------------

sqlParser::CharTypeContext* sqlParser::CharTypeDefContext::charType() {
  return getRuleContext<sqlParser::CharTypeContext>(0);
}

sqlParser::CharTypeDefContext::CharTypeDefContext(TypeContext *ctx) { copyFrom(ctx); }


//----------------- FloatTypeDefContext ------------------------------------------------------------------

tree::TerminalNode* sqlParser::FloatTypeDefContext::FLOAT() {
  return getToken(sqlParser::FLOAT, 0);
}

sqlParser::FloatTypeDefContext::FloatTypeDefContext(TypeContext *ctx) { copyFrom(ctx); }


sqlParser::TypeContext* sqlParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 56, sqlParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(215);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case sqlParser::CHAR: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<sqlParser::CharTypeDefContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(212);
        charType();
        break;
      }

      case sqlParser::INT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<sqlParser::IntTypeDefContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(213);
        match(sqlParser::INT);
        break;
      }

      case sqlParser::FLOAT: {
        _localctx = dynamic_cast<TypeContext *>(_tracker.createInstance<sqlParser::FloatTypeDefContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(214);
        match(sqlParser::FLOAT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharTypeContext ------------------------------------------------------------------

sqlParser::CharTypeContext::CharTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* sqlParser::CharTypeContext::CHAR() {
  return getToken(sqlParser::CHAR, 0);
}

tree::TerminalNode* sqlParser::CharTypeContext::OPEN_BRACKET() {
  return getToken(sqlParser::OPEN_BRACKET, 0);
}

tree::TerminalNode* sqlParser::CharTypeContext::DECIMAL_LITERAL() {
  return getToken(sqlParser::DECIMAL_LITERAL, 0);
}

tree::TerminalNode* sqlParser::CharTypeContext::CLOSE_BRACKET() {
  return getToken(sqlParser::CLOSE_BRACKET, 0);
}


size_t sqlParser::CharTypeContext::getRuleIndex() const {
  return sqlParser::RuleCharType;
}


sqlParser::CharTypeContext* sqlParser::charType() {
  CharTypeContext *_localctx = _tracker.createInstance<CharTypeContext>(_ctx, getState());
  enterRule(_localctx, 58, sqlParser::RuleCharType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(217);
    match(sqlParser::CHAR);
    setState(218);
    match(sqlParser::OPEN_BRACKET);
    setState(219);
    match(sqlParser::DECIMAL_LITERAL);
    setState(220);
    match(sqlParser::CLOSE_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> sqlParser::_decisionToDFA;
atn::PredictionContextCache sqlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN sqlParser::_atn;
std::vector<uint16_t> sqlParser::_serializedATN;

std::vector<std::string> sqlParser::_ruleNames = {
  "root", "sqlStatements", "sqlStatement", "emptyStatement", "selectQuery", 
  "selectTarget", "optionalWhereClause", "whereClause", "whereConditions", 
  "whereCondition", "whereOP", "dropIndexQuery", "dropTableQuery", "createIndexQuery", 
  "createTableQuery", "columnDefinitions", "columnDefinition", "primaryKeyDefinition", 
  "insertQuery", "literalValues", "deleteQuery", "quitStatement", "execfileStatement", 
  "tableName", "columnName", "indexName", "literal", "op", "type", "charType"
};

std::vector<std::string> sqlParser::_literalNames = {
  "", "", "", "", "", "'select'", "'insert'", "'delete'", "'drop'", "'create'", 
  "'quit'", "'execfile'", "'table'", "'index'", "'*'", "'from'", "'into'", 
  "'on'", "", "'('", "')'", "'where'", "'and'", "'or'", "'<>'", "'<='", 
  "'>='", "'<'", "'>'", "'='", "'char'", "'int'", "'float'", "'unique'", 
  "", "", "", "'primary key'", "'values'", "','", "';'"
};

std::vector<std::string> sqlParser::_symbolicNames = {
  "", "SPACE", "SPEC_MYSQL_COMMENT", "COMMENT_INPUT", "LINE_COMMENT", "SELECT", 
  "INSERT", "DELETE", "DROP", "CREATE", "QUIT", "EXECFILE", "TABLE", "INDEX", 
  "WILDCARD", "FROM", "INTO", "ON", "QUOTE", "OPEN_BRACKET", "CLOSE_BRACKET", 
  "WHERE", "AND", "OR", "NOT_EQUAL", "SMALLER_EQUAL", "GREATER_EQUAL", "SMALLER", 
  "GREATER", "EQUAL", "CHAR", "INT", "FLOAT", "UNIQUE", "DECIMAL_LITERAL", 
  "STRING_LITERAL", "REAL_LITERAL", "PRIMARY_KEY", "VALUES", "COMMA", "SEMICOLON", 
  "DQUOTA_STRING", "TOKEN", "ERROR_RECONGNIGION"
};

dfa::Vocabulary sqlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> sqlParser::_tokenNames;

sqlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2d, 0xe1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 
    0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 
    0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 
    0x9, 0x1f, 0x3, 0x2, 0x5, 0x2, 0x40, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x48, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x4b, 0xb, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x51, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x5c, 0xa, 0x4, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x6a, 0xa, 0x8, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0x73, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x76, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 
    0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x6, 0x11, 0x98, 0xa, 0x11, 0xd, 
    0x11, 0xe, 0x11, 0x99, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0xa5, 0xa, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0xb6, 0xa, 0x15, 0xc, 0x15, 0xe, 
    0x15, 0xb9, 0xb, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0xd5, 0xa, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 
    0x3, 0x1e, 0x5, 0x1e, 0xda, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x2, 0x2, 0x20, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 
    0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
    0x3a, 0x3c, 0x2, 0x3, 0x3, 0x2, 0x24, 0x26, 0x2, 0xda, 0x2, 0x3f, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x49, 0x3, 0x2, 0x2, 0x2, 0x6, 0x5b, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x5d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5f, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0xe, 0x69, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x14, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x18, 0x7d, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x81, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x85, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x97, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0xa4, 0x3, 0x2, 0x2, 0x2, 0x24, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x28, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xbc, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0xc1, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xc3, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x32, 0xc8, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0xca, 0x3, 0x2, 0x2, 0x2, 0x36, 0xcc, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x3a, 0xd9, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0xdb, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x40, 0x5, 0x4, 0x3, 0x2, 0x3f, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x3, 0x2, 0x2, 0x2, 0x40, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x2, 0x2, 0x3, 0x42, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x43, 0x44, 0x5, 0x6, 0x4, 0x2, 0x44, 0x45, 0x7, 0x2a, 
    0x2, 0x2, 0x45, 0x48, 0x3, 0x2, 0x2, 0x2, 0x46, 0x48, 0x5, 0x8, 0x5, 
    0x2, 0x47, 0x43, 0x3, 0x2, 0x2, 0x2, 0x47, 0x46, 0x3, 0x2, 0x2, 0x2, 
    0x48, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x49, 0x47, 0x3, 0x2, 0x2, 0x2, 0x49, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x4d, 0x5, 0x6, 0x4, 0x2, 0x4d, 0x4e, 0x7, 
    0x2a, 0x2, 0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x51, 0x5, 0x8, 
    0x5, 0x2, 0x50, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4f, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x5, 0x3, 0x2, 0x2, 0x2, 0x52, 0x5c, 0x5, 0xa, 0x6, 0x2, 
    0x53, 0x5c, 0x5, 0x18, 0xd, 0x2, 0x54, 0x5c, 0x5, 0x1a, 0xe, 0x2, 0x55, 
    0x5c, 0x5, 0x1c, 0xf, 0x2, 0x56, 0x5c, 0x5, 0x1e, 0x10, 0x2, 0x57, 0x5c, 
    0x5, 0x26, 0x14, 0x2, 0x58, 0x5c, 0x5, 0x2a, 0x16, 0x2, 0x59, 0x5c, 
    0x5, 0x2c, 0x17, 0x2, 0x5a, 0x5c, 0x5, 0x2e, 0x18, 0x2, 0x5b, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x5b, 0x53, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x54, 0x3, 
    0x2, 0x2, 0x2, 0x5b, 0x55, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x56, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x58, 0x3, 0x2, 0x2, 
    0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5b, 0x5a, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x7, 0x2a, 0x2, 0x2, 0x5e, 
    0x9, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x7, 0x7, 0x2, 0x2, 0x60, 0x61, 
    0x7, 0x10, 0x2, 0x2, 0x61, 0x62, 0x7, 0x11, 0x2, 0x2, 0x62, 0x63, 0x5, 
    0xc, 0x7, 0x2, 0x63, 0x64, 0x5, 0xe, 0x8, 0x2, 0x64, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x65, 0x66, 0x5, 0x30, 0x19, 0x2, 0x66, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x67, 0x6a, 0x5, 0x10, 0x9, 0x2, 0x68, 0x6a, 0x3, 0x2, 0x2, 0x2, 
    0x69, 0x67, 0x3, 0x2, 0x2, 0x2, 0x69, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6a, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x17, 0x2, 0x2, 0x6c, 0x6d, 
    0x5, 0x12, 0xa, 0x2, 0x6d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x74, 0x5, 
    0x14, 0xb, 0x2, 0x6f, 0x70, 0x5, 0x16, 0xc, 0x2, 0x70, 0x71, 0x5, 0x14, 
    0xb, 0x2, 0x71, 0x73, 0x3, 0x2, 0x2, 0x2, 0x72, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x73, 0x76, 0x3, 0x2, 0x2, 0x2, 0x74, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x13, 0x3, 0x2, 0x2, 0x2, 0x76, 
    0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x5, 0x32, 0x1a, 0x2, 0x78, 0x79, 
    0x5, 0x38, 0x1d, 0x2, 0x79, 0x7a, 0x5, 0x36, 0x1c, 0x2, 0x7a, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x7c, 0x7, 0x18, 0x2, 0x2, 0x7c, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0xa, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0xf, 
    0x2, 0x2, 0x7f, 0x80, 0x5, 0x34, 0x1b, 0x2, 0x80, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x7, 0xa, 0x2, 0x2, 0x82, 0x83, 0x7, 0xe, 0x2, 0x2, 
    0x83, 0x84, 0x5, 0x30, 0x19, 0x2, 0x84, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x85, 
    0x86, 0x7, 0xb, 0x2, 0x2, 0x86, 0x87, 0x7, 0xf, 0x2, 0x2, 0x87, 0x88, 
    0x5, 0x34, 0x1b, 0x2, 0x88, 0x89, 0x7, 0x13, 0x2, 0x2, 0x89, 0x8a, 0x5, 
    0x30, 0x19, 0x2, 0x8a, 0x8b, 0x7, 0x15, 0x2, 0x2, 0x8b, 0x8c, 0x5, 0x32, 
    0x1a, 0x2, 0x8c, 0x8d, 0x7, 0x16, 0x2, 0x2, 0x8d, 0x1d, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8f, 0x7, 0xb, 0x2, 0x2, 0x8f, 0x90, 0x7, 0xe, 0x2, 0x2, 
    0x90, 0x91, 0x5, 0x30, 0x19, 0x2, 0x91, 0x92, 0x7, 0x15, 0x2, 0x2, 0x92, 
    0x93, 0x5, 0x20, 0x11, 0x2, 0x93, 0x94, 0x5, 0x24, 0x13, 0x2, 0x94, 
    0x95, 0x7, 0x16, 0x2, 0x2, 0x95, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 
    0x5, 0x22, 0x12, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x21, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0x32, 0x1a, 
    0x2, 0x9c, 0x9d, 0x5, 0x3a, 0x1e, 0x2, 0x9d, 0x9e, 0x7, 0x29, 0x2, 0x2, 
    0x9e, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa0, 0x5, 0x32, 0x1a, 0x2, 0xa0, 
    0xa1, 0x5, 0x3a, 0x1e, 0x2, 0xa1, 0xa2, 0x7, 0x23, 0x2, 0x2, 0xa2, 0xa3, 
    0x7, 0x29, 0x2, 0x2, 0xa3, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0xa4, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa5, 0x23, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xa7, 0x7, 0x27, 0x2, 0x2, 0xa7, 0xa8, 0x7, 0x15, 0x2, 
    0x2, 0xa8, 0xa9, 0x5, 0x32, 0x1a, 0x2, 0xa9, 0xaa, 0x7, 0x16, 0x2, 0x2, 
    0xaa, 0x25, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x8, 0x2, 0x2, 0xac, 
    0xad, 0x7, 0x12, 0x2, 0x2, 0xad, 0xae, 0x5, 0x30, 0x19, 0x2, 0xae, 0xaf, 
    0x7, 0x28, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x28, 0x15, 0x2, 0xb0, 0x27, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb2, 0x7, 0x15, 0x2, 0x2, 0xb2, 0xb7, 0x5, 0x36, 
    0x1c, 0x2, 0xb3, 0xb4, 0x7, 0x29, 0x2, 0x2, 0xb4, 0xb6, 0x5, 0x36, 0x1c, 
    0x2, 0xb5, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 
    0x7, 0x16, 0x2, 0x2, 0xbb, 0x29, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 
    0x9, 0x2, 0x2, 0xbd, 0xbe, 0x7, 0x11, 0x2, 0x2, 0xbe, 0xbf, 0x5, 0x30, 
    0x19, 0x2, 0xbf, 0xc0, 0x5, 0xe, 0x8, 0x2, 0xc0, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xc2, 0x7, 0xc, 0x2, 0x2, 0xc2, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc4, 0x7, 0xd, 0x2, 0x2, 0xc4, 0xc5, 0x7, 0x25, 0x2, 0x2, 0xc5, 
    0x2f, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x7, 0x2c, 0x2, 0x2, 0xc7, 0x31, 
    0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x2c, 0x2, 0x2, 0xc9, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0xca, 0xcb, 0x7, 0x2c, 0x2, 0x2, 0xcb, 0x35, 0x3, 0x2, 
    0x2, 0x2, 0xcc, 0xcd, 0x9, 0x2, 0x2, 0x2, 0xcd, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0xce, 0xd5, 0x7, 0x1f, 0x2, 0x2, 0xcf, 0xd5, 0x7, 0x1a, 0x2, 0x2, 
    0xd0, 0xd5, 0x7, 0x1d, 0x2, 0x2, 0xd1, 0xd5, 0x7, 0x1b, 0x2, 0x2, 0xd2, 
    0xd5, 0x7, 0x1e, 0x2, 0x2, 0xd3, 0xd5, 0x7, 0x1c, 0x2, 0x2, 0xd4, 0xce, 
    0x3, 0x2, 0x2, 0x2, 0xd4, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd0, 0x3, 
    0x2, 0x2, 0x2, 0xd4, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xda, 0x5, 0x3c, 0x1f, 0x2, 0xd7, 0xda, 0x7, 0x21, 0x2, 0x2, 
    0xd8, 0xda, 0x7, 0x22, 0x2, 0x2, 0xd9, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd9, 
    0xd7, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xda, 0x3b, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x7, 0x20, 0x2, 0x2, 0xdc, 0xdd, 0x7, 
    0x15, 0x2, 0x2, 0xdd, 0xde, 0x7, 0x24, 0x2, 0x2, 0xde, 0xdf, 0x7, 0x16, 
    0x2, 0x2, 0xdf, 0x3d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x3f, 0x47, 0x49, 0x50, 
    0x5b, 0x69, 0x74, 0x99, 0xa4, 0xb7, 0xd4, 0xd9, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

sqlParser::Initializer sqlParser::_init;
