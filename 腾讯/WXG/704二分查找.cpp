#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ret = binarysearch(nums,target,0,nums.size()-1);
        return ret;
    }
    int binarysearch(vector<int>& nums,int target,int left,int right)
    {
        if(left>right)
            return -1;
        int mid = (right-left)/2+left;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target)
        {
            //左边
            return binarysearch(nums,target,left,mid-1);
        }
        else if(nums[mid]<target)
        {
            return binarysearch(nums,target,mid+1,right);
        }
        return -1;
    }
};