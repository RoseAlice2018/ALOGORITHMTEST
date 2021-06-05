#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int partition(vector<int>& nums,int l,int r)
    {
        int pivot = nums[r];
        int i = l;
        for(int j=l;j<=r-1;++j)
        {
            if(nums[j]<pivot)
            {
                swap(nums[j],nums[i]);
                i++;
            }
        }       
        swap(nums[i],nums[r]);
        return i;
    }
    int randomsized_partition(vector<int>& nums,int l,int r)
    {
        int i = rand() % (r-l+1) + l;//随机选一个作为主元
        swap(nums[r],nums[i]);
        return partition(nums,l,r);       
    }
    void randomsized_quicksort(vector<int>& nums,int l,int r)
    {
        if(l < r)
        {
            int pos = randomsized_partition(nums,l,r);
            randomsized_quicksort(nums,l,pos-1);
            randomsized_quicksort(nums,pos+1,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        randomsized_quicksort(nums,0,(int)nums.size()-1);
        return nums;
    }
};