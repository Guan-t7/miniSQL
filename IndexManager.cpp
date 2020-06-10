#include"IndexManager.h"
#include<iostream>
#include<vector>

using namespace std;
using p_Entry = tuple<unsigned, unsigned>;

IndexManager::IndexManager()
{
    map<int, IndexInfo*>::iterator tmp;
    for(tmp=IndexMap.begin(); tmp !=IndexMap.end(); tmp++)
    {
        CreateIndex(tmp->second->Type, tmp->second->IndexName, tmp->second->TableName, tmp->second->Attribute);
    }
}

IndexManager::~IndexManager()
{
}

void* IndexManager::CreateIndex(int Type, string IndexName, string TableName, string Attribute)
{
    IndexInfo *idx = new IndexInfo;

    idx->Type = Type;
    idx->IndexName = IndexName;
    idx->TableName = TableName;
    idx->Attribute = Attribute;
    int size;
    if(Type==-1)
	{
		size = sizeof(int);
		BPlusTree<int> *T = new BPlusTree<int>(IndexName,size);
		idx->BTree = T;
		IndexMap.insert(pair<int,IndexInfo*>(IndexMap.size()+1,idx));
		return T;
	}
	else if(Type == 0)
	{
		size = sizeof(float);
		BPlusTree<float> *T = new BPlusTree<float>(IndexName,size);
		idx->BTree = T;
		IndexMap.insert(pair<int,IndexInfo*>(IndexMap.size()+1,idx));
		return T;
	}
	else if(Type>0 && Type <= 255)
	{
		size = Type + 1;
		BPlusTree<string> *T = new BPlusTree<string>(IndexName,size);
		idx->BTree = T;
		IndexMap.insert(pair<int,IndexInfo*>(IndexMap.size()+1,idx));
		return T;
	}
}

int IndexManager::DropIndex(string IndexName)
{
	map<int, IndexInfo*>::iterator tmp;
	void* T = NULL;
	for(tmp = IndexMap.begin();tmp!=IndexMap.end();tmp++)
	{
		if(IndexName == tmp->second->IndexName)
		{
			T=tmp->second->BTree;
			if(tmp->second->Type == -1)
			{
				BPlusTree<int>* b = (BPlusTree<int>*)T;
				b->DropTree(b->root);
			}
			else if(tmp->second->Type == 0)
			{
				BPlusTree<float>* b = (BPlusTree<float>*)T;
				b->DropTree(b->root);
			}
			else
			{
				BPlusTree<int>* b = (BPlusTree<int>*)T;
				b->DropTree(b->root);
			}
			IndexMap.erase(tmp);
			return 0;
		}
	}
	return 1;
}

void IndexManager::ConvertKey(int Type, string Key)
{
	stringstream s;
	s << Key;
	if(Type == -1)
		s >> this->ck.inttype;
	else if(Type == 0)
		s >> this->ck.floattype;
	else if(Type>0 && Type <=255)
		s >> this->ck.stringtype;
	else
		return;
}

void* IndexManager::GetIndex(string IndexName)
{
	map<int, IndexInfo*>::iterator tmp;
	for(tmp=IndexMap.begin();tmp!=IndexMap.end();tmp++)
	{
		if(IndexName == tmp->second->IndexName)
			return tmp->second->BTree;
	}
	return NULL;
}

tuple IndexManager::IndexSearch(int Type,string IndexName, string Key)
{
	ConvertKey(Type, Key);
	
	if(Type == -1)
	{
		BPlusTree<int>* T = (BPlusTree<int>*)GetIndex(IndexName);
		int result;
		result = stoi(key);
		return T->Search(result);
	}
	else if(Type == 0)
	{
		BPlusTree<float>* T = (BPlusTree<float>*)GetIndex(IndexName);
		float result;
		result = stof(key);
		return T->Search(result);
	}
	else
	{
		BPlusTree<string>* T = (BPlusTree<string>*)GetIndex(IndexName);
		return T->Search(result);
	}
}

//Conditon 0为小于 1为小于等于 2为大于 3为大于等于
vector<tuple> IndexManager::IndexConditionSearch(int Type, string IndexName, string Key, int Condition)
{
	ConvertKey(Type, Key);
	if(Type == -1)
	{
		BPlusTree<int>* T = (BPlusTree<int>*)GetIndex(IndexName);
		int result;
		result = stoi(key);
		return T->ConditionSearch(result,Conditon);
	}
	else if(Type == 0)
	{
		BPlusTree<float>* T = (BPlusTree<float>*)GetIndex(IndexName);
		float result;
		result = stof(key);
		return T->ConditionSearch(result,Condition);
	}
	else
	{
		BPlusTree<string>* T = (BPlusTree<string>*)GetIndex(IndexName);
		return T->ConditionSearch(result,Condition);
	}
}

void IndexManager::IndexInsertion(int Type, string IndexName, string Key,tuple Address)
{
	ConvertKey(Type,Key);
	if(Type == -1)
	{
		BPlusTree<int>* T = (BPlusTree<int>*)GetIndex(IndexName);
		int result;
		result = stoi(key);
		T->Insertion(result,Address);
	}
	else if(Type == 0)
	{
		BPlusTree<float>* T = (BPlusTree<float>*)GetIndex(IndexName);
		float result;
		result = stof(key);
		return T->Insertion(result,Address);
	}
	else
	{
		BPlusTree<string>* T = (BPlusTree<string>*)GetIndex(IndexName);
		T->Insertion(result,Address);
	}
}

void IndexManager::IndexDeletion(int Type, string IndexName, string Key)
{
	ConvertKey(Type,Key);
	if(Type == -1)
	{
		BPlusTree<int>* T = (BPlusTree<int>*)GetIndex(IndexName);
		int result;
		result = stoi(key);
		T->Deletion(result);
	}
	else if(Type == 0)
	{
		BPlusTree<float>* T = (BPlusTree<float>*)GetIndex(IndexName);
		float result;
		result = stof(key);
		T->Deletion(result);
	}
	else
	{
		BPlusTree<string>* T = (BPlusTree<string>*)GetIndex(IndexName);
		T->Deletion(result);
	}
}

void IndexManager::IndexUpdate(int Type, string IndexName, string Key, tuple Address)
{
	ConvertKey(Type,Key);
	if(Type == -1)
	{
		BPlusTree<int>* T = (BPlusTree<int>*)GetIndex(IndexName);
		int result;
		result = stoi(key);
		T->Deletion(result);
		T->Insertion(result,Address);
	}
	else if(Type == 0)
	{
		BPlusTree<float>* T = (BPlusTree<float>*)GetIndex(IndexName);
		float result;
		result = stof(key);
		T->Deletion(result);
		T->Insertion(result,Address);
	}
	else
	{
		BPlusTree<string>* T = (BPlusTree<string>*)GetIndex(IndexName);
		T->Deletion(result);
		T->Insertion(result,Address);
	}
}

