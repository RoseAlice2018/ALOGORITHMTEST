/*
    一种特殊的链表节点类描述如下：
public class Node {
public int value;
public Node next;
public Node rand;
public Node(int data) {
this.value = data;
} }
    Node 类中的 value 是节点值，next 指针和正常单链表中 next 指针的意义一样，都指向下一
个节点，rand 指针是 Node 类中新增的指针，这个指针可能指向链表中的任意一个节点，也可
能指向 null。
给定一个由 Node 节点类型组成的无环单链表的头节点 head，请实现一个函数完成这个链
表中所有结构的复制，并返回复制的新链表的头节点。例如：链表 1->2->3->null，假设 1 的 rand
指针指向 3，2 的 rand 指针指向 null，3 的 rand 指针指向 1。复制后的链表应该也是这种结构，
比如，1′->2′->3′->null，1′的 rand 指针指向 3′，2′的 rand 指针指向 null，3′的 rand 指针指向 1′，
最后返回 1′。
    进阶：不使用额外的数据结构，只用有限几个变量，且在时间复杂度为 O(N)内完成原问题
要实现的函数。         

*/
#include<map>
struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int _val){
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        std::map<Node*,Node*> copymap;
        Node* cur = head;
        while(cur != nullptr)
        {
            Node* node = new Node(cur->val);
            copymap.insert(cur,node);
            cur = cur->next;
        }           
        cur = head;
        while (cur != nullptr)
        {
            copymap[cur]->next = copymap[cur->next];
            copymap[cur]->random = copymap[cur->random];
            cur = cur->next;
        }
        return copymap[head];
    }
};
/*
    o(N)的时间复杂度
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;
        Node* cur = head;
        Node* next = nullptr;
        //复制并链接每一个节点
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        Node* curCopy = nullptr;
        //设置复制节点的rand指针
        while (cur != nullptr)
        {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->random = cur->random != nullptr ?cur->random->next : nullptr;
            cur = next;
        } 
        Node* res = head->next;
        cur = head;
        //拆分
        while (cur != nullptr)
        {
            next = cur->next->next;
            curCopy=cur->next;
            cur->next = next;
            curCopy->next = next !=nullptr?next->next:nullptr;
            cur =next;
        }
        return res;
    }
};