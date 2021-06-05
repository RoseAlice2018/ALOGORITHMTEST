#include<vector>
#include<queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};



class Solution {
public:
    vector<int> ret;
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
            return ret;
        queue<TreeNode*> tmp;
        tmp.push(root);
        //ret.push_back(root->val);
        while(!tmp.empty())
        {
            queue<TreeNode*> layer;
            TreeNode* t = tmp.front();
            TreeNode* r = tmp.back();
            ret.push_back(r->val);
            while(t!=nullptr)
            {
                if(t->left)
                    layer.push(t->left);
                if(t->right)
                    layer.push(t->right);
                tmp.pop();
                t = tmp.empty()?nullptr:tmp.front();
            }
            tmp=layer;
        }
        return ret;
    }
};