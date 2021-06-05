#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        int ret =1;
        for(int i=1;i<arr.size();i++)
        {
            int before = arr[i-1];
            int now = arr[i];
            if(now-before>1)
            { 
                now = before+1;
                arr[i] = now;
            }
            if(now>ret)
                ret = now;
        }
        return ret;
    }
};
