#pragma once
#include <vector>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include "BufferManager.h"

using namespace std;

template<typename TreeNode>
class Node
{
private:
    int degree;
public:
    Node* Parent;
    Node* Next;
    size_t KeyNum;
    bool Leaf;
    vector<TreeNode> key;
    vector<Node*> child;
    vector<char*> value;

    Node(int degree, bool isLeaf = false);
    ~Node(); 
    bool Root();
    Node* Divide(TreeNode &Key);
    bool Search(TreeNode Key, size_t &Flag);
    bool Move(size_t Flag);
    size_t Add(TreeNode &Key);
    size_t Add(TreeNode &Key, char* val);
    
};

template<typename TreeNode>
Node<TreeNode>::Node(int d, bool isLeaf):Parent(NULL),Next(NULL),KeyNum(0),Leaf(isLeaf),degree(d)
{
    for(size_t i =0; i<=degree;i++)
    {
        key.push_back(TreeNode());
        child.push_back(NULL);
        value.push_back(char*());
    }
    child.push_back(NULL);
}

template<typename TreeNode>
Node<TreeNode>::~Node()
{
}

template<typename TreeNode>
bool Node<TreeNode>::Root()
{
    if(Parent == NULL)
        return true;
    else
        return false;
}

template<typename TreeNode>
Node<TreeNode>* Node<TreeNode>::Divide(TreeNode &Key)
{
    size_t mid = (degree-1)/2;
    Node* n = new Node(degree, this->Leaf);
    if(n == NULL)
    {
        cout << "ERROR:Can not find the memory of TreeNode in divide " << Key <<endl;
        exit(2);
    }

    if(!Leaf)
    {
        Key=key[mid];
        for(size_t i =mid+1;i<degree;i++)
        {
            n->key[i-mid-1]=this->key[i];
            this->key[i] = TreeNode();
            n->child[i-mid-1]=this->child[i];
            n->child[i-mid-1]->Parent = n;
            this->child[i]=NULL;
        }
        n->child[degree-mid-1]=this->child[degree];
        n->chila[degree-mid-1]->Parenet=n;
        this->child[degree]=NULL;
        this->key[mid]=TreeNode();
        n->Parent = this->Parent;
        n->KeyNum = mid;
        this->KeyNum = mid;
    }
    else
    {
        Key=key[mid+1];
        for(size_t i =mid+1;i<degree;i++)
        {
            n->key[i-mid-1]=this->key[i];
            this->key[i] = TreeNode();
            n->value[i-mid-1]=this->value[i]
            this->value[i]=char*();
        }
        n->Next = this->Next;
        this->Next=n;
        n->Parent = this->Parent;
        n->KeyNum = mid;
        this->KeyNum = mid+1;
    }

    return n;   
}

template<typename TreeNode>
bool Node<TreeNode>::Search(TreeNode Key, size_t &Flag)
{
    if(KeyNum != 0)
    {
        if(key[0]>Key)
        {
            Flag=0;
            return false;
        }
        else if(key[KeyNum-1]<Key)
        {
            Flag=KeyNum;
            return false;
        }
        else if(KeyNum <= 20)
        {
            for(size_t i =0;i<KeyNum;i++)
            {
                if(key[i]==Key)
                {
                    Flag = i;
                    return true;
                }
                else if(key[i] <Key)
                {
                    continue;
                }
                else 
                {
                    Flag=i;
                    return false;
                }
            }
        }
        else if(KeyNum>20)
        {
            size_t left=0, right = KeyNum-1, idx = 0;
            while(right>left+1)
            {
                idx=(left+right)/2;
                if(key[idx]==Key)
                {
                    Flag=idx;
                    return true;
                }
                else if(key[idx]<Key)
                {
                    left=idx;
                }
                else if(key[idx]>Key)
                {
                    right=idx;
                }
            }

            if(key[left] >= Key)
            {
                Flag = left;
                if(key[left]==Key)
                    return true;
                else
                    return false;
            }
            else if(key[right]>=Key)
            {
                Flag=right;
                if(key[right]==Key)
                    return true;
                else
                    return false;
            }
            else if(key[right]<Key)
            {
                Flag=right+1;
                return false;
            }
        }
    }
    else
    {
        Flag =0;
        return false;
    }
    
    return false;
}

template<typename TreeNode>
bool Node<TreeNode>::Move(size_t &Flag)
{
    if(Flag<=KeyNum)
    {
        if(Leaf)
        {
            for(size_t i=Flag;i<KeyNum-1;i++)
            {
                key[i]=key[i+1];
                value[i]=value[i+1];
            }
            key[KeyNum-1]=TreeNode();
            value[KeyNum-1]=char*();
        }
        else
        {
            for(size_t i=Flag;i<KeyNum-1;i++)
            {
                key[i]=key[i+1];
                child[i+1]=child[i+2];
            }
            key[KeyNum-1]=TreeNode();
            child[KeyNum]=NULL;
        }
        KeyNum--;
        return true;  
    }
    else
    {
        cout << "ERROR:Can not find this node!" <<endl;
        return false;
    }
    
}

template<typename TreeNode>
size_t Node<TreeNode>::Add(TreeNode &Key)
{
    if(KeyNum>0)
    {
        size_t idx = 0;
        bool test = Search(Key,idx);
        if(test)
        {
            cout << "ERROR:This key is already exist!" <<endl;
            exit(3);
        }
        else
        {
            for(size_t i=KeyNum;i>idx;i--)
            {
                key[i]=key[i-1];
                child[i+1]=child[i];
            }
            key[idx]=Key;
            child[idx+1]=NULL;
            KeyNum++;
            return idx;
        }
    }
    else if(KeyNum == 0)
    {
        key[0] = Key;
        KeyNum++;
        return 0;
    }
}

template<typename TreeNode>
size_t Node<TreeNode>::Add(TreeNode &Key, char* val)
{
    if(!Leaf)
    {
        cout << "ERROR:Can not add node with values into non-leaf node!" << endl;
        return -1;
    }
    else if(KeyNum>0)
    {
        size_t idx = 0;
        bool test = Search(Key,idx);
        if(test)
        {
            cout << "ERROR:This key is already exist!" <<endl;
            exit(3);
        }
        else
        {
            for(size_t i=KeyNum;i>idx;i--)
            {
                key[i]=key[i-1];
                value[i]=value[i-1];
            }
            key[idx]=Key;
            value[idx]=val;
            KeyNum++;
            return idx;
        }
    }
    else if(KeyNum == 0)
    {
        key[0] = Key;
        value[0] = val;
        KeyNum++;
        return 0;
    }
}