#pragma once
#include<string>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
#include<sstream>
#include"BPlusTree.h"
#include"API.h"
#include"BufferManager.h"
#include"BPlusTreeNode.h"


using namespace std;

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



void* IndexManager::CreateIndex(int Type, string IndexName, string TableName, string Attribute);


int IndexManager::DropIndex(string IndexName);


ConvertKey(int Type, string Key);


void* IndexManager::GetIndex(string IndexName);


char* IndexManager::IndexSearch(int Type,string IndexName, string Key);


//Conditon 0为小于 1为小于等于 2为大于 3为大于等于
vector<char*> IndexManager::IndexConditionSearch(int Type, string IndexName, string Key, int Condition);


IndexInsertion(int Type, string IndexName, string Key,char* Address);


IndexDeletion(int Type, string IndexName, string Key);


IndexUpdate(int Type, string IndexName, string Key, char* Address);
};