#include<vector>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int Max_number = nums[0];
        int second_number = 0;
        int ret = 0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>Max_number)
            {
                
                second_number = Max_number;
                Max_number = nums[i];
                ret = i;
            }
            else if(nums[i]>second_number)
            {
                second_number = nums[i];
            }
        }
        if(Max_number >= 2 * second_number)
        {
            return ret;
        }
        else 
        {
            return  -1;
        }
    }
};