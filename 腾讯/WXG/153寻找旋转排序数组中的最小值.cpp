#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int low,high;
    int findMin(vector<int>& nums) {
        if(nums[0]<nums[nums.size()-1])
            return nums[0];
        low = nums[0];
        high = nums[nums.size()-1];
        return toMin(nums,0,nums.size()-1);
    }
    int toMin(vector<int>& nums,int left,int right)
    {
        if(left>right)
            return 0;
        if(left==right)
            return nums[left];
        int mid = (right-left)/2+left;
        if(nums[mid]>low)
            return toMin(nums,mid+1,right);
        else if(nums[mid]<high)
            return toMin(nums,left,mid);
        else 
            return nums[right];
    }
};