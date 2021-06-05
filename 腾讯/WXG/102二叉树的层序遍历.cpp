#include<vector>
#include<queue>
using namespace std;
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
    vector<vector<int> > ret;
    vector<int> tmp;
    vector<vector<int> > levelOrder(TreeNode* root) {
        if(root==NULL)
            return ret;
        queue<TreeNode*> list;
        list.push(root);
        while(!list.empty())
        {
            queue<TreeNode*> newlist;
            while(!list.empty())
            {
                         tmp.push_back(list.front()->val);
            if(list.front()->left)
                newlist.push(list.front()->left);
            if(list.front()->right)
                newlist.push(list.front()->right);
            list.pop();   
            }
            ret.push_back(tmp);
            tmp.clear();
            list=newlist;
        }
        return ret;
    }
};