#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[](const vector<int>& a,const vector<int>& b)
        {
            return a[0] == b[0] ? (a[1] < b[1]) : (a[0] > b[0]);
        });

        int MaxDef = 0;
        int ans = 0;
        for(auto& p : properties)
        {
            if(p[1] < MaxDef){
                ans++;
            }else {
                MaxDef = p[1];
            }
        }        
        return ans;
    }
};
