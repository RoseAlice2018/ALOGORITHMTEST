#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        stack<int> maxnum;
        int max_value = nums[nums.size()-1];
        maxnum.push(max_value);
        for(int i = nums.size()-2;i >= 1; i--)
        {
            if(nums[i]>max_value)
            {
                max_value = nums[i];
            }                       
            maxnum.push(max_value);            
        }
        int ret = -1;
        for(int i = 0;i<nums.size()-1;i++)
        {
            max_value = maxnum.top();
            if(max_value-nums[i]>ret&&max_value-nums[i]>0)
            {
                ret = max_value - nums[i];                               
            }
            maxnum.pop();
        }
        return ret;
    }
};