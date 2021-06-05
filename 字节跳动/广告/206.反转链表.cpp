#include<iostream>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(NULL){}
    ListNode(int x):val(x),next(NULL){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* beforehead = NULL;
        ListNode* begin = head;  
        while(begin!=NULL)
        {
            ListNode* tmp = begin->next;
            begin->next = beforehead;
            beforehead = begin;
            begin = tmp;
        }
        return beforehead;
    }
};