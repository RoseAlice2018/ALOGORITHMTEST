#include<vector>
#include<set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> numSet;
        for(int i=0;i<=min(k,int(nums.size()-1));i++)
        {
            if(numSet.count(nums[i]))
            {
                return true;
            }
            numSet.insert(nums[i]);
        }
        for(int i = 1 ; i+k<nums.size();i++)
        {
            numSet.erase(nums[i-1]);
            if(numSet.count(nums[i+k]))
            {
                return true;
            }
            numSet.insert(nums[i+k]);
        }
        return false;
    }
};