#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = -__INT_MAX__;
        int begin = 0;
        int temp = 0;
        for(int i = begin;i<nums.size();i++)
        {
            temp += nums[i];
            if(temp>max)
                max = temp;
            if(temp<=0)
            {
                temp = 0;                
            }
        }
        return max;       
    }
};