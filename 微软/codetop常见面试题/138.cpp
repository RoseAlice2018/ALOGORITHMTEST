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