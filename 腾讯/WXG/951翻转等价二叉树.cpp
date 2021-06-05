struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
};
class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==nullptr&&root2==nullptr)
            return true;
        else if(root1==nullptr||root2==nullptr)
            return false;
        if(root1->val != root2->val)
            return false;
        if(flipEquiv(root1->left,root2->left)&&flipEquiv(root1->right,root2->right))
            return true;
        if(flipEquiv(root1->left,root2->right)&&flipEquiv(root1->right,root2->left))
            return true;
        return false;
    }
};