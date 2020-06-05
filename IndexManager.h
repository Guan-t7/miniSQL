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


using namespace std;

typedef char* value;

struct IndexInfo
{
public:
	//type��ʾ�������ͣ�-1Ϊint��0Ϊfloat��1-255Ϊchar
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


value IndexManager::IndexSearch(int Type,string IndexName, string Key);


//Conditon 0ΪС�� 1ΪС�ڵ��� 2Ϊ���� 3Ϊ���ڵ���
vector<value> IndexManager::IndexConditionSearch(int Type, string IndexName, string Key, int Condition);


IndexInsertion(int Type, string IndexName, string Key,value Address);


IndexDeletion(int Type, string IndexName, string Key);


IndexUpdate(int Type, string IndexName, string Key, value Address);
};