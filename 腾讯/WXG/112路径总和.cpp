 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum,0);
    }
    bool dfs(TreeNode* root,int targetSum,int pathSum)
    {
        if(root==NULL)
            return false;
        if(root->left==NULL&&root->right==NULL)
        {
            pathSum+=root->val;
            if(pathSum==targetSum)
                return true;
            else 
                return false;
        }
        pathSum+=root->val;
        bool left = dfs(root->left,targetSum,pathSum);
        bool right = dfs(root->right,targetSum,pathSum);
        return left||right;
    }
};