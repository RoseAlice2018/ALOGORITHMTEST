#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
};

class Solution {
public:
    vector<vector<int> > ret;
    vector<int> tmp;
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum,0,tmp);
        return ret;
    }
    void dfs(TreeNode* root,int target,int pathSum,vector<int>& tmp)
    {
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
        {
            //leaf node
            pathSum+=root->val;
            if(pathSum==target)
            {
                tmp.push_back(root->val);
                ret.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(root->val);
        pathSum+=root->val;
        dfs(root->left,target,pathSum,tmp);
        dfs(root->right,target,pathSum,tmp);
        tmp.pop_back();
    }
};