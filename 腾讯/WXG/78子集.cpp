#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > ret;
    vector<int> tmp;
    vector<vector<int> > subsets(vector<int>& nums) {
        getsubset(nums,tmp,0);
        return ret;
    }
    void getsubset(vector<int>& nums,vector<int> tmp,int index)
    {
        if(index==nums.size())
        {
            ret.push_back(tmp);
            return;
        }
       
            //input
            tmp.push_back(nums[index]);
            getsubset(nums,tmp,index+1);
            tmp.pop_back();
            //output
            getsubset(nums,tmp,index+1);
        
    }
};