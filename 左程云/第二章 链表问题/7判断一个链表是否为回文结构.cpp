/*
给定一个链表的头节点 head，请判断该链表是否为回文结构。
例如：
1->2->1，返回 true。 1->2->2->1，返回 true。
15->6->15，返回 true。 1->2->3，返回 false。
进阶：
如果链表长度为 N，时间复杂度达到 O(N)，额外空间复杂度达到 O(1)。    
*/
#include<utility>
struct ListNode{
    int val;
    ListNode* next;
    ListNode():value(0),next(nullptr){}
};

/*
利用额外的空间
略
*/
/*
    进阶：以O（1）的额外空间
*/
class Solution {
public:
    int getNum(ListNode* head)
    {
        int ret = 0;
        while(head!=nullptr)
        {
            ret++;
            head= head->next;
        }
        return ret;
    }
    std::pair<ListNode*,ListNode*> reverseList(ListNode* head,int num,int flag)
    {
        int count = 0;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(count < num)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            count++;
        }
        if(flag==1)
        {
            //奇数
            return std::pair<ListNode*,ListNode*>(pre,cur->next);
        }
        else 
            //偶数
            return std::pair<ListNode*,ListNode*>(pre,cur);
    }
    bool isPalindrome(ListNode* head) {
        int num = getNum(head);
        int mid = num%2==0?num/2:(num-1)/2;
        std::pair<ListNode*,ListNode*> ret = reverseList(head,mid,num%2);
        ListNode* l1=ret.first;
        ListNode* l2=ret.second;
        while(l1!=nullptr&&l2!=nullptr)
        {
            if(l1->val!=l2->val)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
};