struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};

/*
给定一棵二叉树的头节点 head，按照如下两种标准分别实现二叉树边界节点的逆时针打印。
标准一：
1．头节点为边界节点。
2．叶节点为边界节点。 
3．如果节点在其所在的层中是最左的或最右的，那么该节点也是边界节点。

标准二：
1．头节点为边界节点。 
2．叶节点为边界节点。 
3．树左边界延伸下去的路径为边界节点。 
4．树右边界延伸下去的路径为边界节点。
*/


