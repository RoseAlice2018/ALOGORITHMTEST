#include<vector>
using namespace std;
//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

class Solution {
    void inorder(TreeNode* node,vector<int>& res){
        if(node){
            inorder(node->left,res);
            res.push_back(node->val);
            inorder(node->right,res);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nums1,nums2;
        inorder(root1,nums1);
        inorder(root2,nums2);

        vector<int> mergerd;
        auto p1 = nums1.begin(),p2 = nums2.begin();
        while (true)
        {
            if(p1 == nums1.end()){
                mergerd.insert(mergerd.end(),p2,nums2.end());
                break;
            }
            if(p2==nums2.end())
            {
                mergerd.insert(mergerd.end(),p1,nums1.end());
                break;
            }
            if(*p1 < *p2)
            {
                mergerd.push_back(*p1++);
            }
            else{
                mergerd.push_back(*p2++);
            }
        }
        return mergerd;
        
    }
};