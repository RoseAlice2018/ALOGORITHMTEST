#include<iostream>
using namespace std;
 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(NULL), right(NULL) {}
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    void inorder(TreeNode* root,int& pre,int& ans){
        if(root == NULL){
            return;
        }
        inorder(root->left,pre,ans);
        if(pre == -1){
            pre = root->val;
        }else {
            ans = min(ans,root->val-pre);
            pre = root->val;
        }
        inorder(root->right,pre,ans);
    }
    int minDiffInBST(TreeNode* root) {
        int ans = __INT_MAX__,pre = -1;
        inorder(root,pre,ans);
        return ans;
    }
};