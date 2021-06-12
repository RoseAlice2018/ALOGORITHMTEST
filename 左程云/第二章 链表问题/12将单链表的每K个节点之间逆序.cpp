/*
    给定一个单链表的头节点 head，实现一个调整单链表的函数，使得每 K 个节点之间逆序，
如果最后不够 K 个节点一组，则不调整最后几个节点。
    例如：
链表：1->2->3->4->5->6->7->8->null，K=3。
调整后为：3->2->1->6->5->4->7->8->null。其中 7、8 不调整，因为不够一组。
*/
#include<stack>
using namespace std;
struct Node
{
    int val;
    Node* next;
    Node():val(0),next(nullptr){}
};

Node* reverseKNode(Node* head,int K)
{
    if (K < 2)
    {
        return head;
    }    
    stack<Node*> Nodes ;
    Node* newHead = head;
    Node* cur = head;
    Node* pre = nullptr;
    Node* next = nullptr;
    while (cur!=nullptr)
    {
        next = cur->next;
        Nodes.push(cur);
        if(Nodes.size()==K)
        {
            pre = resgin1(Nodes,pre,next);
            newHead = newHead==head?cur:newHead;
        }
        cur = next;
    }
    return newHead;    
}
Node* resgin1(stack<Node*> Nodes,Node* left,Node* right)
{
    Node* cur = Nodes.top();Nodes.pop();
    if(left!=nullptr)
    {
        left->next =cur;
    }
    Node* next = nullptr;
    while(!Nodes.empty())
    {
        next = Nodes.top();Nodes.pop();
        cur->next = next;
        cur = next;
    }
    cur->next = right;
    return cur;
}

Node* reverseNode2(Node* head,int K)
{
    if(K < 2)
        return head;
    Node* cur = head;
    Node* start = nullptr;
    Node* pre = nullptr;
    Node* next = nullptr;
    int count = 1;
    while(cur != nullptr)
    {
        next = cur->next;
        if (count == K)
        {
            start = pre==nullptr?head:pre->next;
            head = pre==nullptr?cur:head;
            resign2(pre,start,cur,next);
            pre = start;
            count = 0;
        }
        count++;
        cur = next;
    }
    return head;
}
void resign2(Node* left,Node* start,Node* end,Node* right)
{
    Node* pre = start;
    Node* cur = pre->next;
    Node* next = nullptr;
    while(cur != right)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    if(left!=nullptr)
    {
        left->next = end;
    }
    start->next = right;
}