#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        int min_val = nums[0];
        int ret = 0;
        for(int i= 1;i<nums.size();i++)
        {
            if(nums[i]>min_val)
                min_val = nums[i];
            else 
            {
                ret += min_val - nums[i] + 1;
                nums[i] = min_val + 1;
                min_val = nums[i];
            }
        }
        return ret;
    }
};