/*
    对二叉树的节点来说，有本身的值域，有指向左孩子节点和右孩子节点的两个指针；对双
向链表的节点来说，有本身的值域，有指向上一个节点和下一个节点的指针。在结构上，两种
结构有相似性，现在有一棵搜索二叉树，请将其转换为一个有序的双向链表。
例如，节点定义为：
public class Node {
public int value;
public Node left;
public Node right;
public Node(int data) {
this.value = data;
} }
一棵搜索二叉树如图 2-11 所示。
图 2-11
这棵搜索二叉树转换后的双向链表从头到尾依次是 1～9。对每一个节点来说，原来的 right
指针等价于转换后的 next 指针，原来的 left 指针等价于转换后的 last 指针，最后返回转换后的
双向链表头节点。
6 2 4 7 5 1 3 9 8    

*/
#include<queue>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node():val(0),left(nullptr),right(nullptr){}
    Node(int x,Node* _left,Node*_right):val(x),left(_left),right(_right){}
};
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
};
/*
    用队列等容器收集二叉树中序遍历结果的方法。时间复杂度为 O(N)，额外空间复
杂度为 O(N)，具体过程如下：
1．生成一个队列，记为 queue，按照二叉树中序遍历的顺序，将每个节点放入 queue 中。 
2．从 queue 中依次弹出节点，并按照弹出的顺序重连所有的节点即可
*/

Node* TreetoDoubleNode(TreeNode* root)
{

}

/*
    递归算法
    利用递归函数，除此之外，不使用任何容器的方法。时间复杂度为 O(N)，额外空
间复杂度为 O(h)，h 为二叉树的高度。
    具体过程为先把以 X 为头的搜索二叉树的左子树转换为有序双向链表，并且返回左子树有
序双向链表的头和尾，然后把以 X 为头的搜索二叉树的右子树转换为有序双向链表，并且返回
右子树有序双向链表的头和尾，接着通过 X 把两部分接起来即可。最后不要忘记，递归函数对
任何节点的要求是一样的，所以要返回此时大的有序双向链表的头和尾。具体实现请参看如下
代码中的 convert2 方法    
*/