#include<iostream>
using namespace std;
#define nullptr 0
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      ListNode* before = new ListNode();
      before->next = head;
      ListNode* cur = head;
      ListNode* ret = before;
      while(cur!=nullptr&&cur->next!=nullptr)
      {
        if(cur->next->val==cur->val)
        {
          int cur_duplicate_val = cur->val;
          while(cur->val==cur_duplicate_val)
          {
            cur = cur->next;
            if(cur==nullptr)
              break;
          }
          if(cur==nullptr)
          {
            //over 到此为止
            before->next = nullptr;
            break;
          }
          else 
          {
            //找到了下一个节点
            before->next = cur;
          }
        }
        else 
        {
          before = cur;
          cur = cur->next;
        }
      }
      return ret->next;
    }
};