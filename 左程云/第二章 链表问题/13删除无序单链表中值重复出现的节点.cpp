/*
    给定一个无序单链表的头节点 head，删除其中值重复出现的节点。
    例如：1->2->3->3->4->4->2->1->1->null，删除值重复的节点之后为 1->2->3->4->null。
请按以下要求实现两种方法。
方法 1：如果链表长度为 N，时间复杂度达到 O(N)。
方法 2：额外空间复杂度为 O(1)。       

*/
#include<set>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node():val(0),next(nullptr){}
};

void removeRep1(Node* head)
{
    if(head == nullptr)
    {
        return;
    }
    set<int> _set ;
    Node* pre = head;
    Node* cur = head->next;
    _set.insert(head->val);
    while(cur != nullptr)
    {
        if(_set.count(cur->val))
        {
            pre->next = cur->next;
        }
        else 
        {
            _set.insert(cur->val);
            pre = cur;
        }
        cur = cur->next;
    }
}