/*
给定一个链表的头节点 head，请判断该链表是否为回文结构。
例如：
1->2->1，返回 true。 1->2->2->1，返回 true。
15->6->15，返回 true。 1->2->3，返回 false。
进阶：
如果链表长度为 N，时间复杂度达到 O(N)，额外空间复杂度达到 O(1)。    
*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){}
};

