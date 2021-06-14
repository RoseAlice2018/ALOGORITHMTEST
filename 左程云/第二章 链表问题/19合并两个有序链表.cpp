/*
    给定两个有序单链表的头节点 head1 和 head2，请合并两个有序链表，合并后的链表依然
有序，并返回合并后链表的头节点。
例如：
0->2->3->7->null
1->3->5->7->9->null
合并后的链表为：0->1->2->3->3->5->7->7->9->null  


*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){}
    Node(int _value):value(_value),next(nullptr){}
};
Node* merge(Node* l1,Node* l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    Node* head = new Node();
    Node* p = head;
    while(l1!=nullptr&&l2!=nullptr)
    {
        if(l1->value<l2->value)
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        else 
        {
            p->next =l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    while(l1!=nullptr)
    {
        p->next = l1;
        l1= l1->next;
    }
    while(l2!=nullptr)
    {
        p->next = l2;
        l2 = l2->next;
    }
    return head->next;
}