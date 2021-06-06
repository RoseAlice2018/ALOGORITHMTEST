/*
    给定两个有序链表的头指针head1和head2，打印两个链表的公共部分。
*/
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
    Node(int x):value(x),next(nullptr){};
};

void printCommonPart(Node* head1,Node* head2)
{
    while(head1!=nullptr&&head2!=nullptr)
    {
        if(head1->value>head2->value)
        {
            head2=head2->next;
            continue;
        }        
        else if(head1->value<head2->value)
        {
            head1=head1->next;
            continue;
        }
        else 
        {
            printf("%d ",head1->value);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
}
