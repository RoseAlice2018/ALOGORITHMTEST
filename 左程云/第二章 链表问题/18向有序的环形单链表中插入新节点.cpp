/*
    一个环形单链表从头节点 head 开始不降序，同时由最后的节点指回头节点。给定这样一个
环形单链表的头节点 head 和一个整数 num，请生成节点值为 num 的新节点，并插入到这个环
形链表中，保证调整后的链表依然有序。
*/

struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){}
    Node(int _value):value(_value),next(nullptr){}
};

Node* insertNum(Node* head,int num)
{
    Node* node = new Node(num);
    if(head == nullptr)
    {
        node->next = node;
        return node;
    }    
    Node* pre = head;
    Node* cur = head->next;
    while(cur!=head)
    {
        if(pre->value<=num&&cur->next>=num)
        {
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    pre->next = node;
    node->next = cur;
    return head->value<num?head:node;
}