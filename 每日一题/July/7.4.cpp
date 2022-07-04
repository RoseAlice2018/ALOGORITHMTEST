#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ret;
        int min_gap=INT32_MAX;
        for(int i=0;i+1<arr.size();i++)
        {
            int gap = arr[i+1] - arr[i];
            if(gap<min_gap)
            {
                ret.clear();
                vector<int> tmp;
                tmp.push_back(arr[i]);
                tmp.push_back(arr[i+1]);
                ret.push_back(tmp);
                min_gap = gap;
            }
            else if(gap == min_gap)
            {
                vector<int> tmp;
                tmp.push_back(arr[i]);
                tmp.push_back(arr[i+1]);
                ret.push_back(tmp);                
            }
        }
        return ret;
    }
};