/*
    分别实现反转单向链表和反转双向链表的函数
*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
    Node(int x):value(x),next(nullptr){};
};

Node* reverseList(Node* head)
{
    Node* pre = nullptr;
    Node* next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}

/*
    反转双向链表的函数如下
*/
struct Node{
    int value;
    Node* next;
    Node* before;
    Node():value(0),next(nullptr){};
    Node(int x):value(x),next(nullptr){};
};

Node* reverseList(Node* head)
{
    Node* pre = nullptr;
    Node* next = nullptr;
    while (head != nullptr)
    {
        next = head->next;
        head->next = pre;
        head->before = next;
        pre = head;
        head = next;
    }
    return pre;
}
