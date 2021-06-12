/*
    给定一个链表的头节点 head 和一个整数 num，请实现函数将值为 num 的节点全部删除。
例如，链表为 1->2->3->4->null，num=3，链表调整后为：1->2->4->null。 

*/
struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){}
};

void removeval(int target,Node* head)
{
    if(head==nullptr)
        return;
    Node* cur = head;
    while (cur->val==target)
    {
        cur = cur->next;
    }
    Node* pre = cur;
    cur = cur->next;
    while(cur!=nullptr)
    {
        while(cur->val==target)
            cur =cur->next;
        pre->next =cur;
        pre = cur;
        cur =cur->next;
    }
    
}