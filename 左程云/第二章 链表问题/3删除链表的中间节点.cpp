/*
    给定链表的头节点 head，实现删除链表的中间节点的函数。
例如：
不删除任何节点；
1->2，删除节点 1； 1->2->3，删除节点 2； 1->2->3->4，删除节点 2； 1->2->3->4->5，删除节点 3；
进阶：
给定链表的头节点 head、整数 a 和 b，实现删除位于 a/b 处节点的函数。
例如：
链表：1->2->3->4->5，假设 a/b 的值为 r。
如果 r 等于 0，不删除任何节点；
如果 r 在区间(0, 1/5]上，删除节点 1；
如果 r 在区间(1/5, 2/5]上，删除节点 2；
如果 r 在区间(2/5, 3/5]上，删除节点 3；
如果 r 在区间(3/5, 4/5]上，删除节点 4；
如果 r 在区间(4/5, 1]上，删除节点 5；
如果 r 大于 1，不删除任何节点。    

*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
    Node(int x):value(x),next(nullptr){};
};

Node* removeMidNode(Node* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    if (head->next->next == nullptr)
    {
        return head->next;        
    }
    Node* pre = head;
    Node* cur = head->next->next;
    while (cur->next != nullptr && cur->next->next != nullptr)
    {
        pre = pre->next;
        cur = cur->next->next;
    }
    pre->next = pre->next->next;
    return head;
}