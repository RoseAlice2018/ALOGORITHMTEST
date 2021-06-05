
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* begin = head;
        ListNode* second = head->next;
        ListNode* ret = head;
        ListNode* two = second;
        while(begin!=nullptr && second != nullptr)
        {
            begin->next = second->next;
            if(second->next!=nullptr)
                second->next = second->next->next;
            else 
                break;                
            begin = begin->next;
            second = second->next;
        }
        begin->next=two;
        return ret;
    }
};