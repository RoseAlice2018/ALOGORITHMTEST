/*
    分别实现两个函数：
    一个可以删除单链表中倒数第K个节点
    可以删除双链表中倒数第K个节点
*/

struct single_Node{
    int value;
    single_Node* next;
    single_Node():val(0),next(nullptr){};
    single_Node(int val):value(val),next(nullptr){};
};
/*  
    在单链表中删除倒数第K个节点
*/
single_Node* GoK(single_Node* head,int K)
{
    while(K--)
    {
        head = head->next;
    }
    return head;
}
single_Node* delete_K(single_Node* head,int K)
{
    single_Node* slow = head;
    single_Node* fast = GoK(head,K);
    if(fast==nullptr)
    {
        return slow->next;
    }
    while(fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }
    if(fast->next==nullptr)
    {
        slow->next = slow->next->next;
    }
    return head;
}

/*
    方法二：
    让链表从头开始走到尾，每移动一步，就让 K 值减 1，当链表走到
结尾时，如果 K 值大于 0，说明不用调整链表，因为链表根本没有倒数第 K 个节点，此时将原
链表直接返回即可；如果 K 值等于 0，说明链表倒数第 K 个节点就是头节点，此时直接返回
head.next，也就是原链表的第二个节点，让第二个节点作为链表的头返回即可，相当于删除头
节点；接下来，说明一下如果 K 值小于 0，该如何处理。
先明确一点，如果要删除链表的头节点之后的某个节点，实际上需要找到要删除节点的前
一个节点，比如：1->2->3，如果想删除节点 2，则需要找到节点 1，然后把节点 1 连到节点 3 上（1->3），以此来达到删除节点 2 的目的。
如果 K 值小于 0，如何找到要删除节点的前一个节点呢？方法如下：
1．重新从头节点开始走，每移动一步，就让 K 的值加 1。 2．当 K 等于 0 时，移动停止，移动到的节点就是要删除节点的前一个节点。
这样做是非常好理解的，因为如果链表长度为 N，要删除倒数第 K 个节点，很明显，倒数
第 K 个节点的前一个节点就是第 N-K 个节点。在第一次遍历后，K 的值变为 K-N。第二次遍历时，
K 的值不断加 1，加到 0 就停止遍历，第二次遍历当然会停到第 N-K 个节点的位置。        

*/

single_Node* removeKthNode(single_Node* head,int K)
{
    if(head==nullptr || K < 1)
    {
        return head;
    }
    single_Node* cur = head;
    while(cur != nullptr)
    {
        K--;
        cur = cur->next;
    }
    if(K==0)
    {
        head = head->next;
        return head;
    }
    else if(K<0)
    {
        cur = head;
        while (++K != 0)
        {
            cur = cur->next;
        }        
        cur->next = cur->next->next;
    }
    return head;
}






















/*
    在双链表中删除倒数第K个节点
    delete the Kth node from the bottom in double-link list
*/
struct doubleNode{
    int value;
    doubleNode* next;
    doubleNode* pre;
    doubleNode():value(0),next(nullptr),pre(nullptr){}
    doubleNode(int val):value(val),next(nullptr),pre(nullptr){}
};
