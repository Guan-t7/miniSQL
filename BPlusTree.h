#pragma once
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "BufferManager.h"
#include "BPlusTreeNode.h"

using namespace std;
using p_Entry =tuple<unsigned,unsigned>;

struct SearchNode
{
    Node<Tree>* ptr;
    size_t position;
    bool Exist;
};

template<typename Tree>
class BPlusTree
{
private:
    Node<Tree>* Head;
    string FileName;
    int degree;
    int KeySize;
    size_t KeyNum;
    size_t KeyLevel;
    size_t NodeNum;

    void InitTree();
    bool FindNode(Node<Tree>* p, Tree Key, SearchNode &s);
    bool InsertionAdjust(Node<Tree>* p);
    bool DeletionAdjust(Node<Tree>* p);
public:
    Node<Tree>* Root;
    BPlusTree(string IndexName, int Keysize, int degree = 5);
    ~BPlusTree();
    tuple Search(Tree &Key);
    vector<tuple> ConditionSearch(Tree &Key, int Condition);
    bool Insertion(Tree &Key, tuple Address);
    bool Deletion(Tree &Key);
    void DropTree(Node<Tree>* p);
};

template<typename Tree>
BPlusTree<Tree>::BPlusTree(string IndexName, int Keysize, int d):Head(NULL),degree(d),KeySize(Keysize),KeyNum(0),KeyLevel(0),NodeNum(0),Root(NULL)
{
    string FileName = "INDEX_"+IndexName+".idx";
    this->FileName = FileName;
    InitTree();
}

template<typename Tree>
BPlusTree<Tree>::~BPlusTree()
{
    DropTree(Root);
    KeyLevel = 0;
    KeyNum = 0;
    Root = NULL;
}

template<typename Tree>
void BPlusTree<Tree>::InitTree()
{
    Root = new Node<Tree>(degree, true);
    KeyNum=0;
    KeyLevel =1;
    NodeNum =1;
    Head=Root;
}

template<typename Tree>
bool BPlusTree<Tree>::FindNode(Node<Tree>* p, Tree Key, SearchNode &s)
{
    size_t idx = 0;
    if(p->Search(Key, idx))
    {
        if(!p->Leaf)
        {
            p = p->child[idx+1];
            while(!p->Leaf)
                p=p->child[0];
            s.ptr = p;
            s.position = 0;
            s.Exist = true;
        }
        else
        {
            s.ptr = p;
            s.position = idx;
            s.Exist = true;
        }
    }
    else
    {
        if(!p->Leaf)
        {
           FindKey(p->child[idx],Key,s)
        }
        else
        {
            s.ptr = p;
            s.position = idx;
            s.Exist = false;
        }
    }
}

template<typename Tree>
bool BPlusTree<Tree>::InsertionAdjust(Node<Tree>* p)
{
    Tree Key;
    Node<Tree>* n = p->Divide(Key);
    NodeNum+=1;
    if(p->Root())
    {
        Node<Tree>* root = new Node<Tree>(degree, false);
        if(root == NULL)
        {
            cout << "ERROR:Can not find the new root!" << endl;
            exit(1);
        }
        else
        {
            this->Root = root;
            KeyLevel+=1;
            NodeNum+=1;
            p->Parent = root;
            n->Parent = root;
            root->Add(Key);
            root->child[0]=p;
            root->child[1]=n;
            return true;
        }
    }
    else
    {
        Node<Tree>* pa = p->Parent;
        size_t idx = pa->Add(Key);
        pa->child[idx+1]=n;
        n->Parent = pa;
        if(pa->KeyNum==degree)
            return InsertionAdjust(pa);
        return true;
    }
    
}

template<typename Tree>
bool BPlusTree<Tree>::Insertion(Tree &Key, tuple Address)
{
    SearchNode sn;
    if(Address == NULL)
        return false;
    SearchNode s;
    if(!Root)
        InitTree();
    FindNode(Root, Key, s);
    if(s.Exist==true)
    {
        cout<< "ERROR:This tuple is already existed!" <<endl;
        return false;
    }
    else
    {
        s.ptr->Add(Key,Address);
        if(s.ptr->KeyNum == degree)
            InsertionAdjust(s.ptr);
        KeyNum+=1;
        return true;
    }
    
    
}
    
template<typename Tree>
void BPlusTree<Tree>::DropTree(Node<Tree>* p)
{
    if(!p->Leaf)
    {
        for(size_t i =0;i<p->KeyNum+1;i++)
        {
            DropTree(p->child[i]);
            p->child[i]=NULL;
        }
    }
    if(!p)
        return;
    delete p;
    NodeNum--;
    return;
}    
    
template<typename Tree> 
tuple BPlusTree<Tree>::Search(Tree &Key)
{
    if(!Root)
        return 0;
    SearchNode s;
    FindNode(Root, Key, s);
    if(s.Exist)
        return s.ptr->value[s.position];
    else
        return NULL;
}  
    
template<typename Tree> 
vector<tuple> BPlusTree<Tree>::ConditionSearch(Tree &Key, int Condition)
{
    vector<tuple> result;
    tuple re;
    SearchNode s;
    if(!Root)
        return result;
    FindNode(Root,Key,s);
    Node<Tree>* pos=s.ptr;
    Node<Tree>* l;

    if(Condition == 0)
    {
        for(l=Head;l!=pos;l=l->Next)
        {
            for(int i =0;i<l->KeyNum;l++)
            {
                re = l->value[i];
                result.push_back(re);
            } 
        }
        if(s.Exist == true)
        {
            for(int i=0;i<pos->KeyNum;i++)
            {
                if(pos->key[i]<Key)
                {
                    r=pos->value[i];
                    result.push_back(re);
                }
            }
        }
    }
    else if(Condition == 1)
    {
        for(l=Head;l!=pos;l=l->Next)
        {
            for(int i =0;i<l->KeyNum;l++)
            {
                re = l->value[i];
                result.push_back(re);
            } 
        }
        if(s.Exist == true)
        {
            for(int i=0;i<pos->KeyNum;i++)
            {
                if(pos->key[i]<=Key)
                {
                    r=pos->value[i];
                    result.push_back(re);
                }
            }
        }
    }
    else if(Condition == 2)
    {
        if(s.Exist == true)
        {
            for(int i=0;i<pos->KeyNum;i++)
            {
                if(pos->key[i]>Key)
                {
                    r=pos->value[i];
                    result.push_back(re);
                }
            }
        }
        for(l=Head;l!=pos;l=l->Next)
        {
            if(l==pos)
                continue;
            for(int i =0;i<l->KeyNum;l++)
            {
                re = l->value[i];
                result.push_back(re);
            } 
        }
    }
    else if(Condition == 3)
    {
        if(s.Exist == true)
        {
            for(int i=0;i<pos->KeyNum;i++)
            {
                if(pos->key[i]>=Key)
                {
                    r=pos->value[i];
                    result.push_back(re);
                }
            }
        }
        for(l=Head;l!=pos;l=l->Next)
        {
            if(l==pos)
                continue;
            for(int i =0;i<l->KeyNum;l++)
            {
                re = l->value[i];
                result.push_back(re);
            } 
        }
    }
    return result;
}

template<typename Tree>
bool BPlusTree<Tree>::DeletionAdjust(Node<Tree>* p)
{
	size_t MinKey = (degree - 1) / 2;
	if (((p->Leaf) && (p->KeyNum >= MinKey)) || ((degree != 3) && (!p->Leaf) && (p->KeyNum >= MinKey - 1))) 
		return  true;

	if (p->Root())
	{
		if (p->KeyNum == 0) 
        {
			if (Root->Leaf) 
			{
				delete p;
				Root = NULL;
				Head = NULL;
				KeyLevel--;
				NodeNum--;
			}
			else 
			{
				Root = p->child[0];
				Root->Parent = NULL;
				delete p;
				KeyLevel--;
				NodeNum--;
			}
		}
        else
            return true;
	}
	else
	{
		Node<Tree>* pa = p->Parent;
        Node<Tree>* bro = NULL;
		if (p->Leaf)
		{
			size_t idx = 0;
			pa->Search(p->key[0], idx);

			if ((pa->child[0] != p) && (idx + 1 == pa->KeyNum))
			{
				bro = pa->child[idx];
				if (bro->KeyNum > MinKey) 
				{
					for (size_t i = p->KeyNum; i > 0; i--)
					{
						p->key[i] = p->key[i - 1];
						p->value[i] = p->value[i - 1];
					}
					p->key[0] = bro->key[bro->KeyNum - 1];
					p->value[0] = bro->value[bro->KeyNum - 1];
					bro->Move(bro->KeyNum - 1);

					p->KeyNum++;
					pa->key[idx] = p->key[0];
					return true;
				} 
				else 
				{
					pa->Move(idx);
					for (int i = 0; i < p->KeyNum; i++)
					{
						bro->key[i + bro->KeyNum] = p->key[i];
						bro->value[i + bro->KeyNum] = p->value[i];
					}
					bro->KeyNum += p->KeyNum;
					bro->Next = p->Next;
					delete p;
					NodeNum--;

					return DeletionAdjust(pa);
				}

			}
			else 
			{
				if (pa->child[0] == p)
					bro = pa->child[1];
				else
					bro = pa->child[idx + 2];
				if (bro->KeyNum > MinKey)
				{
					p->key[p->KeyNum] = bro->key[0];
					p->value[p->KeyNum] = bro->value[0];
					p->KeyNum++;
					bro->Move(0);
					if (pa->child[0] == p)
						pa->key[0] = bro->key[0];
					else
						pa->key[idx + 1] = bro->key[0];
					return true;

				}
				else 
				{
					for (int i = 0; i < bro->KeyNum; i++)
					{
						p->key[p->KeyNum + i] = bro->key[i];
						p->value[p->KeyNum + i] = bro->value[i];
					}
					if (p == pa->child[0])
						pa->Move(0);
					else
						pa->Move(idx + 1);
					p->KeyNum += bro->KeyNum;
					p->Next = bro->Next;
					delete bro;
					NodeNum--;

					return DeletionAdjust(pa);
				}
			}

		}
		else 
		{
			size_t idx = 0;
			pa->search(p->child[0]->key[0], idx);
			if ((pa->child[0] != p) && (idx + 1 == pa->KeyNum)) 
			{
				bro = pa->child[idx];
				if (bro->KeyNum > MinKey - 1) 
				{
					p->child[p->KeyNum + 1] = p->child[p->KeyNum];
					for (size_t i = p->KeyNum; i > 0; i--)
					{
						p->child[i] = p->child[i - 1];
						p->key[i] = p->key[i - 1];
					}
					p->child[0] = bro->child[bro->KeyNum];
					p->key[0] = pa->key[idx];
					p->KeyNum++;
					pa->key[idx] = bro->key[bro->KeyNum - 1];
					if (bro->child[bro->KeyNum])
					{
						bro->child[bro->KeyNum]->pa = p;
					}
					bro->Move(bro->KeyNum - 1);

					return true;

				}
				else
				{
					bro->key[bro->KeyNum] = pa->key[idx];
					pa->Move(idx);
					bro->KeyNum++;

					for (int i = 0; i < p->KeyNum; i++)
					{
						bro->child[bro->KeyNum + i] = p->child[i];
						bro->key[bro->KeyNum + i] = p->key[i];
						bro->child[bro->KeyNum + i]->pa = bro;
					}
					bro->child[bro->KeyNum + p->KeyNum] = p->child[p->KeyNum];
					bro->child[bro->KeyNum + p->KeyNum]->pa = bro;

					bro->KeyNum += p->KeyNum;


					delete p;
					NodeNum--;

					return DeletionAdjust(pa);
				}

			}
			else 
			{
				if (pa->child[0] == p)
					bro = pa->child[1];
				else
					bro = pa->child[idx + 2];
				if (bro->KeyNum > MinKey - 1)
				{
					p->child[p->KeyNum + 1] = bro->child[0];
					p->key[p->KeyNum] = bro->key[0];
					p->child[p->KeyNum + 1]->pa = p;
					p->KeyNum++;
					if (p == pa->child[0])
						pa->key[0] = bro->key[0];
					else
						pa->key[idx + 1] = bro->key[0];
					bro->child[0] = bro->child[1];
					bro->Move(0);

					return true;
				}
				else 
				{

					p->key[p->KeyNum] = pa->key[idx];

					if (p == pa->child[0])
						pa->Move(0);
					else
						pa->Move(idx + 1);

					p->KeyNum++;

					for (int i = 0; i < bro->KeyNum; i++)
					{
						p->child[p->KeyNum + i] = bro->child[i];
						p->key[p->KeyNum + i] = bro->key[i];
						p->child[p->KeyNum + i]->pa = p;
					}
					p->child[p->KeyNum + bro->KeyNum] = bro->child[bro->KeyNum];
					p->child[p->KeyNum + bro->KeyNum]->pa = p;

					p->KeyNum += bro->KeyNum;


					delete bro;
					NodeNum--;

					return DeletionAdjust(pa);

				}

			}

		}

	}
	return false;
}

template<typename Tree>    
bool BPlusTree<Tree>::Deletion(Tree &Key)
{
    SearchNode s;
	if (!Root)
	{
		cout << "ERROR:The tree is empty!" << endl;
		return false;
	}
	else
	{
		FindNode(Root, key, s);
		if (!s.Exist)
		{
			cout << "ERROR:The tree is empty!" << endl;
			return false;
		}
		else
		{
			if (s.ptr->Root())
			{
				s.ptr->Move(s.position);
				KeyNum--;
				return DeletionAdjust(s.ptr);
			}
			else
			{
				if (s.position == 0 && Head != s.ptr)
				{
					size_t idx = 0;
					Node<Tree>* now = s.ptr->Parent;
					bool test = now->Search(Key, idx);
					while (!test)
					{
						if (now->Parent)
							now = now->Parent;
						else
							break;
						test = now->Search(Key, idx);
					}
					now->key[idx] = s.ptr->key[1];

					s.ptr->Move(s.position);
					KeyNum--;
					return DeletionAdjust(s.ptr);

				}
				else 
				{
					s.ptr->Move(s.position);
					KeyNum--;
					return DeletionAdjust(s.ptr);
				}
			}
		}
	}
}