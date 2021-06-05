#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(int a,int b)
    {
        string a1 = to_string(a);
        string b1 = to_string(b);
        for(int i=0;i<max(a1.size(),b1.size());i++)
        {
            char aa,bb;
            if(i>a1.size()-1)
                aa = a1[a1.size()-1];
            if(i>b1.size()-1)
                bb = b1[b1.size()-1];
            if(aa == bb)
            {
                continue;
            }
            else if(aa>bb)
            {
                return true;
            }
            else if(aa<bb)
            {
                return false;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(),nums.end(),cmp);
        for(int i=0;i<nums.size();i++)
            res+=to_string(nums[i]);      
        return res;
    }
};