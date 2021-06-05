
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ret = new ListNode();
        ret->next = head;
        ListNode* begin = head;
        ListNode* end = head;
        ListNode* pre = ret;
        while(end!=nullptr)
        {
            end = end->next;
            if(end==nullptr)
                break;
            if(end->val==begin->val)
            {
                if(end->next==nullptr)
                {
                    pre->next=nullptr;
                    break;
                }
                continue;
            }
            else 
            {
                //kind 1 没有重复
                if(begin->next==end)
                {
                    pre = begin;
                    begin = end;
                    continue;
                }
                //kind 2 有重复
                else 
                {
                    pre->next = end;
                    begin = end;
                    continue;
                }
            }
        }
        return ret->next;
    }
};