#include<vector>
using namespace std;
class Solution {
public:
    int target_left=-1;
    int target_right=-1;
    void binarySearch(vector<int>& nums,int target,int left,int right)
    {
        if(left>right)return;
        int mid = (right-left)/2+left;
        if(nums[mid]==target)
        {
            if(target_left==-1&&target_right==-1)
            {
                target_left=mid;
                target_right=mid;
            }
            else if(mid<target_left)
                target_left=mid;
            else if(mid>target_right)
                target_right=mid;
            binarySearch(nums,target,left,mid-1);
            binarySearch(nums,target,mid+1,right);
        }
        else if(nums[mid]<target)
        {
            binarySearch(nums,target,mid+1,right);
        }
        else if(nums[mid]>target)
        {
            binarySearch(nums,target,left,mid-1);
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        binarySearch(nums,target,0,nums.size()-1);
        vector<int> res;
        res.push_back(target_left);
        res.push_back(target_right);
        return res;
    }
};