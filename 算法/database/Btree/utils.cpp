#include "utils.h"
#include <iostream>
using namespace std;
//#include "B+_node.h"
pair<LeafNode*,int>find(int value)
{
    //假设没有重复码，返回叶子节点C，和索引i，使得C.Pi指向第一条搜索码等于value的记录
    Node* C = root;
    while(C->kind != LeafNodekind)
    {
        NormalNode* tmp_C = (NormalNode*)C;
        bool isFindinChild = false;
        for(int i=0;i<C->key_num-1;i++)
        {
            if(value<C->key_Values[i])
            {
                C = tmp_C->childs[i];
                isFindinChild = true;
                break;
            }
            else if(value==C->key_Values[i])
            {
                C = tmp_C->childs[i+1];
                isFindinChild = true;
                break;
            }
        }        
        if (!isFindinChild)
            C = tmp_C->childs[C->key_num-1];
    }
    if (C->kind == LeafNodekind)
    {
        LeafNode* tmpc = (LeafNode*)C;
        for(int i = 0;i<C->key_num;i++)
        {
            if(value == tmpc->datas[i])
            {
                return pair<LeafNode*,int>(tmpc,i);
            }
        }
        return pair<LeafNode*,int>(NULL,0);
    }
};