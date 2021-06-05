#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(NULL) {}
      ListNode(int x) : val(x), next(NULL) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution{
    public:
        //翻转一个子链表，并且返回新的头与尾
        pair<ListNode*,ListNode*>flip(ListNode* head,ListNode* tail){
           ListNode* prev = tail->next;
           ListNode* p = head;
           while(prev != tail){
               ListNode* next = p->next;
               p->next=prev;
               prev = p;
               p=next;
           }
           return {tail,head}; 
        }
        ListNode* reverseKGroup(ListNode* head,int k)
        {
            ListNode* hair = new ListNode(0);
            hair->next = head;
            ListNode* pre = hair;

            while(head)
            {
                ListNode* tail = pre;
                for(int i=0;i<k;++i)
                {
                    tail = tail->next;
                    if(!tail){
                        return hair->next;
                    }
                }
                ListNode* nex = tail->next;
                pair<ListNode*,ListNode*>result = flip(head,tail);
                head = result.first;
                tail = result.second;
                pre->next = head;
                tail->next = nex;
                pre = tail;
                head = tail->next;
            }
            return hair->next;
        }
};