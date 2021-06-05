
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr)
            return new TreeNode(val);
        if(root->left==nullptr&&root->right==nullptr)
        {
            TreeNode* new_node = new TreeNode(val);
            if(root->val>val)
                root->left = new_node;
            else if(root->val < val)
                root->right = new_node;
            return root;
        }
        if(root->val>val)
        {
            if(root->left==nullptr)
            {
                TreeNode* new_node = new TreeNode(val);
                root->left = new_node;
                return root;
            }
            insertIntoBST(root->left,val);
        }
        else if(root->val<val)
        {
            if(root->right==nullptr)
            {
                TreeNode* new_node = new TreeNode(val);
                root->right = new_node;
                return root;
            }
            insertIntoBST(root->right,val);
        }
        return root;
    }
};