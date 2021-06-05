#include<vector>
#include<algorithm>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> index;
        for(int i=0;i<nums.size();i++)
        {
            index[nums[i]]=i;            
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
            int tmp = target-nums[i];
            if(index.count(tmp)&&i!=index[tmp])
            {
                ret.push_back(i);
                ret.push_back(index[tmp]);
                return ret;
            }
        }
        return ret;
    }
};