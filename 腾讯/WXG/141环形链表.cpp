 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==nullptr)return false;
        ListNode* begin = head;
        ListNode* nextNode = head;
        while(begin!=nullptr&&nextNode!=nullptr)
        {
            begin = begin->next;
            if( nextNode ->next==nullptr)return false;
            nextNode = nextNode ->next ->next;
            if(nextNode == begin)
                return true;
        }             
        return false;
    }
};