/*
    给定一个单向链表的头节点 head，以及两个整数 from 和 to，在单向链表上把第 from 个节
点到第 to 个节点这一部分进行反转。
*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
};

Node* reverseFT(Node* head,int from,int to)
{
    int len = 0;
    Node* node1 = head;
    Node* fPre = nullptr;
    Node* tPos = nullptr;

    while (node1 != nullptr)
    {
        len++;
        fPre = len == from - 1 ? node1 : fPre;
        tPos = len == to + 1 ? node1 : tPos;
        node1 = node1->next;
    }
    if (from > to || from < 1 || to > len){
        return head;
    }
    node1 = fPre ==nullptr ? head : fPre->next;
    Node* node2 = node1->next;
    node1->next = tPos;
    Node* next = nullptr;
    while(node2!=tPos)
    {
        next = node2->next;
        node2->next = node1;
        node1 =node2;
        node2 = next;
    }
    if (fpr != nullptr)
    {
        fPre->next = node1;
        return head;
    }
    return node1;
}