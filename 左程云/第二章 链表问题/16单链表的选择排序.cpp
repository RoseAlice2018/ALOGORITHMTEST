/*
    给定一个无序单链表的头节点head，实现单链表的选择排序
    要求额外的空间复杂度为O(1)
1．开始时默认整个链表都是未排序的部分，对于找到的第一个最小值节点，肯定是整个链
表的最小值节点，将其设置为新的头节点，记为 newHead。
2．每次在未排序的部分中找到最小值的节点，然后把这个节点从未排序的链表中删除，删
除的过程当然要保证未排序部分的链表在结构上不至于断开。例如，2->1->3，删除节点 1 之后，
链表应该变成 2->3，这就要求我们应该找到要删除节点的前一个节点。
3．把删除的节点（也就是每次的最小值节点）连接到排好序部分的链表尾部。
4．全部过程处理完后，整个链表都已经有序，返回 newHead。
和选择排序一样，如果链表的长度为 N，时间复杂度为 O(N2)，额外空间复杂度为 O(1)。
本题依然是考查调整链表的代码技巧，具体过程请参看如下代码中的 selectionSort 方法。
*/
struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){}
};

Node* selectSort(Node* head)
{
    Node* tail = nullptr;   //排序部分尾部
    Node* cur = head;   // 未排序部分的头部
    Node* smallPre = nullptr ; //最小节点的前一个节点
    Node* small = nullptr;  //最小的节点
    while(cur!=nullptr)
    {
        small = cur;
        smallPre = getSmallestPreNode(cur);
        if (smallPre != nullptr)
        {
            //删除small节点
            small = smallPre->next;
            smallPre->next = small->next;
        }
        cur = cur == small ? cur->next:cur;
        if(tail == nullptr)
        {
            head = small;
        }
        else 
        {
            tail->next = small;
        }
        tail = small;
    }
}

Node* getSmallestPreNode(Node* head)
{
    Node* smallPre = nullptr;
    Node* small = head;
    Node* pre = head;
    Node* cur = pre->next;
    while(cur != nullptr)
    {
        if(cur->val < small->val)
        {
            smallPre = pre;
            small = cur;
        }
        pre =cur;
        cur = cur->next;
    }
    return smallPre;
}