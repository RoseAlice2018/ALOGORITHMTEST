#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ret;
        for(int i = 0;i< nums.size();i++)
        {
            if(nums[i]==i)
                continue;
            else 
            {
                if(nums[nums[i]]==-1)
                {
                    nums[nums[i]] = nums[i];
                     
                }
                if(nums[nums[i]]==nums[i])
                {
                    nums.push_back(nums[i]);
                    nums[i]=-1;
                }
            }                                    
        }               
        return ret;        
    }
};