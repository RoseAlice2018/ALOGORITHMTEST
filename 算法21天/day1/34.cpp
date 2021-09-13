#include<vector>
using namespace std;
class Solution {
public:
    int leftMost = -1;
    int rightMost = -1;
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret ;
        
        binaySearchRange(nums,target,0,nums.size()-1);
        ret.push_back(leftMost);
        ret.push_back(rightMost);
        return ret;     
    }
    void binaySearchRange(vector<int>&nums,int target,int left,int right)
    {
        if(left>right)
            return;
        int mid = (right-left)/2+left;
        if(nums[mid]==target)
        {
            if(leftMost==-1||rightMost==-1)
            {
                leftMost = mid;
                rightMost = mid;
            }
            else if(mid<leftMost)
            {
                leftMost = mid;
            }
            else if(mid > rightMost)
            {
                rightMost = mid;
            }
            binaySearchRange(nums,target,left,mid-1);
            binaySearchRange(nums,target,mid+1,right);
        }
        else 
        {
            if(nums[mid]<target)
            {
                binaySearchRange(nums,target,mid+1,right);
            }
            else 
            {
                binaySearchRange(nums,target,left,mid-1);
            }
        }
    }
};