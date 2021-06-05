
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ret = head;
        ListNode* before = head;
        ListNode* second = head;
        int tmp = 0;
        while(tmp<n)
        {
            tmp++;
            second =second->next;
        }
        if(second==nullptr)
            return head->next;
        while(second->next!=nullptr)
        {
            second = second->next;
            before = before->next;
        }
        if(second->next==nullptr)
            before->next=before->next->next;
        return head;
    }
};