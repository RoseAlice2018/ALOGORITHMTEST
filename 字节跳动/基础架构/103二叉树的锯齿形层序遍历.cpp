#include <vector>
#include <deque>
#include <iostream>
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
    vector<vector<int> > res;
    vector<int> tmp;
    int flag = 0;//0 lefrt to right 1 right to left
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
            return res;
        deque<TreeNode*> layer ;
        layer.push_back(root);
        layerorder(layer,0);
        return res;
    }
    void layerorder(deque<TreeNode*> layer,int flag)
    {
        deque<TreeNode*> newlayer;
        if(flag==0)
        {
            //left to right
            TreeNode* front = layer.front();
            while(!layer.empty())
            {
                tmp.push_back(front->val);
                if(front->left)
                    newlayer.push_back(front->left);
                if(front->right)
                    newlayer.push_back(front->right);
                layer.pop_front();
                front = layer.front();
            }
        }
        else if(flag == 1)
        {
            //right to left
            TreeNode* front = layer.back();
            while(!layer.empty())
            {
                tmp.push_back(front->val);
                if(front->left)
                    newlayer.push_back(front->left);
                if(front->right)
                    newlayer.push_back(front->right);
                layer.pop_back();
                front = layer.back();
            }           
        }
        //该层读取完毕
        res.push_back(tmp);
        tmp.clear();
        //进入下一层
        if(newlayer.size()>0)
        layerorder(newlayer,flag==1?0:1);
    }
};