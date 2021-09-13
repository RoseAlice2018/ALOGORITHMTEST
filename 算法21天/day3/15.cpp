#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > ret;
        for(int i=0;i+2<nums.size();i++)
        {
            vector<int> tmp;
            tmp.push_back(nums[i]);
            if(twoSum(nums,i,tmp))
             ret.push_back(tmp);
            int j;
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[j]!=nums[i])
                    break;
            }
            i = j;
        }
        return ret;
    }
    bool twoSum(vector<int>& nums,int begin,vector<int>& ret)
    {
        int target = - nums[begin];
        int left  = begin + 1;
        int right = nums.size()-1;
        for(int i = left;i<right;)
        {
            if(nums[left]+nums[right]==target)
            {
                ret.push_back(nums[left]);
                ret.push_back(nums[right]);
                return true;
            }
            else 
            {
                if(nums[left]+nums[right]>target)
                {
                    right--;
                }
                else 
                    left++;
            }
        }
        return false;
    }
};