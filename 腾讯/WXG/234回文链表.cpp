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
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode* begin = head;
        while(begin!=NULL)
        {
            size++;
            begin=begin->next;
        }
        int mid=size/2;
        pair<ListNode*,ListNode*> ret = reverse_list(head,mid);
        ListNode* l1=ret.first;
        ListNode* l2=ret.second;
        if(size%2==1)
            l2=l2->next;
        while(l1!=NULL)
        {
            if(l1->val!=l2->val)
                return false;
            l1=l1->next;
            l2=l2->next;
        }
        return true;
    }
    pair<ListNode*,ListNode*> reverse_list(ListNode* head,int count)
    {
        ListNode* prehead=new ListNode();
        //ListNode* ret;
        ListNode* next;
        while(head!=NULL&&count>0)
        {
            next= head->next;
            head->next=prehead;
            prehead=head;
            head=next;
            count--;
        }
        return {prehead,head};
    }
};