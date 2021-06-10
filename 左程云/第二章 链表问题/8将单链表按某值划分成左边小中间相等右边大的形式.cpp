/*
    给定一个单向链表的头节点 head，节点的值类型是整型，再给定一个整数 pivot。实现一个
调整链表的函数，将链表调整为左部分都是值小于 pivot 的节点，中间部分都是值等于 pivot 的
节点，右部分都是值大于 pivot 的节点。除这个要求外，对调整后的节点顺序没有更多的要求。
    例如：链表 9->0->4->5->1，pivot=3。
调整后链表可以是 1->0->4->9->5，也可以是 0->1->9->5->4。总之，满足左部分都是小于 3
的节点，中间部分都是等于 3 的节点（本例中这个部分为空），右部分都是大于 3 的节点即可。
对某部分内部的节点顺序不做要求。
    进阶：
在原问题的要求之上再增加如下两个要求。  在左、中、右三个部分的内部也做顺序要求，要求每部分里的节点从左到右的顺序与
原链表中节点的先后次序一致。
例如：链表 9->0->4->5->1，pivot=3。调整后的链表是 0->1->9->4->5。在满足原问题要求的
同时，左部分节点从左到右为 0、1。在原链表中也是先出现 0，后出现 1；中间部分在本例中
为空，不再讨论；右部分节点从左到右为 9、4、5。在原链表中也是先出现 9，然后出现 4，最
后出现 5。  如果链表长度为 N，时间复杂度请达到 O(N)，额外空间复杂度请达到 O(1)。    
*/


struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
};


ListNode* listPartition2(ListNode* head,int pivot)
{
    ListNode* sH = nullptr; //small head
    ListNode* sT = nullptr; //small tail
    ListNode* eH = nullptr; //equal head
    ListNode* eT = nullptr; //equal tail
    ListNode* bH = nullptr; //big head
    ListNode* bT = nullptr; //big tail
    ListNode* next = nullptr;//reserved next node
    //split all the nodes into three lists
    while (head != nullptr)
    {
        next = head->next;
        head->next = nullptr;
        if (head->val < pivot)
        {
            if(sH==nullptr)
            {
                sH = head;
                sT = head;
            }
            else 
            {
                sT->next = head;
                sT = head;
            }
        }
        else if (head->val == pivot)
        {
            if (eH == nullptr)
            {
                eH = head;
                eT = head;
            }
            else 
            {
                eT->next = head;
                eT = head;
            }
        }
        else 
        {
            if (bH == nullptr)
            {
                bH = head;
                bT = head;
            }
            else 
            {
                bT->next = head;
                bT = head;
            }
        }
        head = next;
    }
    //小的和相等的重新连接
    if (sT != nullptr)
    {
        sT->next = eH;
        eT = eT==nullptr?sT:eT;
    }
    //
    if(eT!=nullptr)
    {
        eT->next = bH;
    }
    return sH!=nullptr?sH:eH!=nullptr?eH:bH;
}