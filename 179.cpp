#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    bool cmp(int a,int b)
    {
        long sx = 10,sy = 10;
        while(sx <= a){
            sx *= 10;
        }
        while(sy <= b){
            sy *= 10;
        }
        return sy*a+ b > sx*b + a;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);     
        if (nums[0] == 0) {
            return "0";
        }
        string ret;
        for (int &x : nums) {
            ret += to_string(x);
        }
        return ret;    
    }
};