#pragma once
#include <stdio.h>
#include <map>
#include <string>
#include <sstream>
#include "BufferManager.h"
#include "SimpleSQLInterpreter/DBInfo.h"

class IndexManager {
public:
	int static const TYPE_FLOAT = 0;
	int static const TYPE_INT = -1;
	//其他数字代表char及其长度，例如10代表char(10)
	map<int, IndexInfo*> indexMap;
	
	//转换输入的数据
	struct keyTmp {
		int intTmp;
		float floatTmp;
		string stringTmp;
	} kt;

	//获取B+树degree
	int getDegree(int type);

	//获取节点的key
	int getKeySize(int type);

	void setKey(int type, string key);


public:


	// 创建/读取index，生成空树
	IndexManager();

	~IndexManager();

	void* createIndex(string indexName,string tableName, string Attribute ,int type);

	int dropIndex(string indexName);

	void* getIndex(string indexName);

	value searchValue(string indexName, string key, int type);

	vector<value> searchValueConditional(string indexName, string key, int type, int direction);

	void insertIndex(string indexName, string key, value recordAddress, int type);

	void deleteIndexByKey(string indexName, string key, int type);

	void updateIndex(string indexName, string key, value recordAddress,int type);


	//从buffer读取index
	void loadIndexInfos();
	//将index写入buffer
	int writeIndexInfosintoBuffer();

	void showallIndexs() {
		map<int, IndexInfo*>::iterator it;
		for (it = indexMap.begin(); it != indexMap.end(); it++) {

			cout << "IndexName"<<it->second->indexName << endl;
			if (it->second->type == -1) {
				BTree<int>* bt;
				bt = (BTree<int>*)it->second->Tree;
			}
		}
	}

};
