#include<iostream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    int ret = 0;
    int k1;
    int kthLargest(TreeNode* root, int k) {
       k1 = k;
       dfs(root);
       return ret;
    }
    void dfs(TreeNode* root)
    {
        if(root == NULL)
            return;
        dfs(root->right);
        if(k1==0)
            return;
        if(--k1==0)ret=root->val;
        dfs(root->left);        
    }
};