
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret ;
        int carry = 0;
        ret = add(l1,l2,carry);
        return ret;
    }
    ListNode* add(ListNode* l1,ListNode* l2,int carry)
    {
        int l1_val = (l1==NULL)?0:l1->val;
        int l2_val = (l2==NULL)?0:l2->val;
        if(l1==NULL&&l2==NULL)
        {
            if(carry==0)
                return NULL;
            else 
                return new ListNode(carry);
        }
        else if(l2==NULL)
        {
            int tmp = l1_val+l2_val+carry;
            if(tmp<10)
            {
                l1->val=tmp;
                carry=0;
                l1->next = add(l1->next,NULL,carry);
                return l1;
            }            
            else if(tmp>=10)
            {
                l1->val=tmp-10;
                carry=1;
                l1->next = add(l1->next,NULL,carry);
                return l1;
            }
        }
        else if(l1 == NULL)
        {
            l1=l2;
            int tmp = l1_val+l2_val+carry;
            if(tmp<10)
            {
                l1->val=tmp;
                carry=0;
                l1->next = add(l1->next,NULL,carry);
                return l1;
            }            
            else if(tmp>=10)
            {
                l1->val=tmp-10;
                carry=1;
                l1->next = add(l1->next,NULL,carry);
                return l1;
            }      
        }
        int tmp = l1_val+l2_val+carry;
        if(tmp<10)
        {
            l1->val=tmp;
            carry = 0;
            l1->next = add(l1->next,l2->next,carry);
            return l1;
        }
        else if(tmp>=10)
        {
            l1->val=tmp-10;
            carry=1;
            l1->next = add(l1->next,l2->next,carry);
            return l1;
        }
        return l1;
    }
};