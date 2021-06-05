#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    int flag = 1;
    ListNode* realhead;
    ListNode* realtail;
    ListNode* findtail(ListNode* head,int k)
    {
        while(k--)
        {
            head=head->next;
            if(head==nullptr)
            {
                 flag=0;
                 break;
            }  
        }
        return head;      
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prehead = new ListNode();
        ListNode* ret = prehead;
        realhead = head;
        realtail = findtail(head,k-1);
        while(flag)
        {
            //find head and tail
            flip(realhead,realtail);
            prehead->next= realtail;
            prehead = head;
            head = head->next;   
             realhead = head;
            realtail = findtail(head,k-1);
        }
        return ret->next;
    }
    void flip(ListNode* head,ListNode* tail)
    {
        ListNode* beforeHead =  nullptr;
        ListNode* tmphead = head;
        ListNode* tmptail = tail;
        while(head!=tail->next)
        {
            ListNode* next= head->next;
            head->next = beforeHead;
            beforeHead = head;
            head = next;    
        }
        //k个节点翻转完成，返回反转后的头尾节点
        realhead = tmptail;
        realtail = tmphead;
    }
};