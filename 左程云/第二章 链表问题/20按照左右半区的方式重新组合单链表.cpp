/*
    给定一个单链表的头部节点 head，链表长度为 N，如果 N 为偶数，那么前 N/2 个节点算作
左半区，后 N/2 个节点算作右半区；如果 N 为奇数，那么前 N/2 个节点算作左半区，后 N/2+1
个节点算作右半区。左半区从左到右依次记为 L1->L2->…，右半区从左到右依次记为
R1->R2->…，请将单链表调整成 L1->R1->L2->R2->…的形式。
    例如：
1->null，调整为 1->null。 1->2->null，调整为 1->2->null。
1->2->3->null，调整为 1->2->3->null。 1->2->3->4->null，调整为 1->3->2->4->null。 1->2->3->4->5->null，调整为 1->3->2->4->5->null。 1->2->3->4->5->6->null，调整为 1->4->2->5->3->6->null。           
*/

struct Node{
    int value;
    Node* next;
    Node(int _value):value(_value),next(nullptr){}
};

void relocate(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return;
    }
    Node* mid = head;
    Node* right = head->next;
    while (right->next != nullptr && right->next->next != nullptr)
    {
        mid = mid->next;
        right = right->next->next;
    }
    right = mid->next;
    mid->next = nullptr;
    mergeLR(head,right);
}
void mergeLR(Node* left,Node* right)
{
    Node* next = nullptr;
    while(left->next != nullptr)
    {
        next = right->next;
        right->next = left->next;
        left->next = right;
        left = right->next;
        right = next;
    }
    left->next = right;
}