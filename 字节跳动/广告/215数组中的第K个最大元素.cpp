#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),[](int a,int b)->bool{return a>b;});
        return nums[k];
    }
};