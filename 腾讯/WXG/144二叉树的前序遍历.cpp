#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr);
};
class Solution {
public:
    vector<int> ret;
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return ret;
    }
    void preorder(TreeNode* root)
    {
        if(root==nullptr)
            return;
        ret.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
};