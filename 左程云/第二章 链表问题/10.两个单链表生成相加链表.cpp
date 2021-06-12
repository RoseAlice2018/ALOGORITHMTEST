/*
    两个单链表生成相加链表
    
    假设链表中每一个节点的值都在 0～9 之间，那么链表整体就可以代表一个整数。
例如：9->3->7，可以代表整数 937。
给定两个这种链表的头节点 head1 和 head2，请生成代表两个整数相加值的结果链表。
例如：链表 1 为 9->3->7，链表 2 为 6->3，最后生成新的结果链表为 1->0->0->0。

*/

struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){};
    Node(int _val):val(_val),next(nullptr){};
};

void AddList(Node* l1,Node* l2)
{
    if(l1==nullptr)
        return l2;
    else if(l2==nullptr)
        return l1;
    int ca = 0;
    Node* ret = new Node();
    Node* res = ret;
    while(l1!=nullptr&&l2!=nullptr)
    {
        int sum = l1->val + l2->val + ca;
        if(sum >= 10)
        {
            ca = 1;
            sum-=10;
            Node* next = new Node(sum);
            ret->next = next;
            ret = ret->next;
        }   
        else 
        {
            Node* next =  new Node(sum);
            ret->next = next;
            ret = ret->next;
        }     
    }
    while(l1!=nullptr)
    {
        //
    }
    while(l2!=nullptr)
    {
        //
    }
    if(ca==1)
    {

    }
    return res->next;
}