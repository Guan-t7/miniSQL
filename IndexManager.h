#pragma once
#include<string>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include"BPlusTree.h"
#include"BPlusTreeNode.h"

using namespace std;
using p_Entry = tuple<unsigned,unsigned>;

struct IndexInfo
{
public:
	//type表示数据类型，-1为int，0为float，1-255为char
	int Type;
	string IndexName;
	string TableName;
	string Attribute;
	void* BTree;
};

class IndexManager
{
public:
	struct convert{
		int inttype;
		float floattype;
		string stringtype;
	}ck;
	
	map<int, IndexInfo*> IndexMap;


IndexManager();

~IndexManager();

void* CreateIndex(int Type, string IndexName, string TableName, string Attribute);

int DropIndex(string IndexName);

void (int Type, string Key);

void* GetIndex(string IndexName);

tuple IndexSearch(int Type,string IndexName, string Key);

//Conditon 0为小于 1为小于等于 2为大于 3为大于等于
vector<tuple> IndexConditionSearch(int Type, string IndexName, string Key, int Condition);

void IndexInsertion(int Type, string IndexName, string Key,tuple Address);

void IndexDeletion(int Type, string IndexName, string Key);

void IndexUpdate(int Type, string IndexName, string Key, tuple Address);
};