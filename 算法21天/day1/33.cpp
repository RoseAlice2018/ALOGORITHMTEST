#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binaryRtxSearch(nums,target,0,nums.size()-1);
    }
    int binaryRtxSearch(vector<int>& nums,int target,int left,int right)
    {
        if(left>right)
            return -1;
        int mid = (right-left)/2+left;
        if(nums[mid]==target)
        {
            return mid;
        }
        else 
        {
            if(nums[mid]<target)
            {
                if(nums[right]>=target||nums[left]<target)
                {
                    return binaryRtxSearch(nums,target,mid+1,right);
                }
                else 
                {
                    return binaryRtxSearch(nums,target,left,mid-1);
                }
            }
            else if(nums[mid]>target)
            {
                int leftMostVal = nums[left];
                int rightMostVal = nums[right];
                if(leftMostVal>target&&rightMostVal>=target)
                {
                    return binaryRtxSearch(nums,target,mid+1,right)||binaryRtxSearch(nums,target,left,mid-1);
                }
                else 
                {
                    return binaryRtxSearch(nums,target,left,mid-1);
                }
            }
        }
        return -1;
    }
};