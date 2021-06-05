
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
    int getsize(ListNode* head)
    {
        int ret=0;
        while(head!=nullptr)
        {
            ret++;
            head=head->next;
        }
        return ret;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* pre = head;
        //if(k==1)return head;
        if(head==nullptr)
            return head;
        int size = getsize(head);
        ListNode* tail=head;
        k %= size;
        if(k==0)
            return head;
        while(k--)
        {
            tail = tail->next;
        }               
        while(tail->next!=nullptr)
        {
            pre=pre->next;
            tail=tail->next;
        }
        ListNode* ret = pre->next;       
        pre->next = nullptr;
        tail->next = head;
        return ret;
    }
};