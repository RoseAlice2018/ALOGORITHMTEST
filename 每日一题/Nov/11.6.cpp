#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            res ^= nums[i];
        }
        for (int i = 0; i <= n; i++) {
            res ^= i;
        }
        return res;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/missing-number/solution/diu-shi-de-shu-zi-by-leetcode-solution-naow/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。