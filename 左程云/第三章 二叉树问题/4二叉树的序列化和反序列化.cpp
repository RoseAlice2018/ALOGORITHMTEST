struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};
/*
二叉树被记录成文件的过程叫作二叉树的序列化，通过文件内容重建原来二叉树的过程叫
作二叉树的反序列化。给定一棵二叉树的头节点 head，已知二叉树节点值的类型为 32 位整型。
请设计一种二叉树序列化和反序列化的方案，并用代码实现。

*/

