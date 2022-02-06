#include <vector>
#include <unorderedmap>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int> state;
        for(int num : nums){
            if(state[num]==0)
            {
                ans += num;
                state[num] = 1;
            }
            else if(state[num]==1){
                ans -= num;
                state[num] = 2;
            }
        }
        return ans;
    }
};