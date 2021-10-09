#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > res;
    void dfs(vector<int>& candidates,int target,int cur,int index,vector<int> path)
    {
        for(int i = index;i<candidates.size();i++)
        {
            if(cur+candidates[i]==target)
            {
                path.push_back(candidates[i]);
                res.push_back(path);
                continue;
            }
            else if(cur+candidates[i]>target)
            {
                return;
            }
            else 
            {
                path.push_back(candidates[i]);
                dfs(candidates,target,cur+candidates[i],i,path);
                path.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0,path);
        return res;
    }
};