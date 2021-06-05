#include<iostream>
using namespace std;
 //* Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA!=NULL&&tempB!=NULL)
        {
            if(tempA==tempB)
                return tempB;
            tempA = tempA->next;
            tempB = tempB->next;
            if(tempA==NULL)
            {
              tempA=headB;
              headB=NULL;
            }
            if(tempB==NULL)
            {
                tempB=headA;
                headA=NULL;
            }
        }
        return NULL;
    }
};