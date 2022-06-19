#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    map<int,int> table;
    int seqfind(TreeNode* root)
    {
       int leftsum =0, rightsum = 0;
       if(root->left!=nullptr)
            leftsum = seqfind(root->left);
       if(root->right!=nullptr)
            rightsum = seqfind(root->right);
       int midsum = leftsum + rightsum + root->val;
       if(table.count(midsum))
        table[midsum]++;
       else 
        table[midsum] = 1;
        return midsum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        seqfind(root);
        vector<int> res;
        int max_ = 0;
        for(auto iter = table.begin();iter!= table.end();iter++)
        {
            if(iter->second > max_)
            {
                max_ = iter->second;
                res.clear();
                res.push_back(iter->first);
            }
            else if(iter->second == max_)
               res.push_back(iter->first); 
        }
        return res;
    }
};