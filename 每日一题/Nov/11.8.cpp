class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        vector<int> cntS(10), cntG(10);
        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            } else {
                ++cntS[secret[i] - '0'];
                ++cntG[guess[i] - '0'];
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; ++i) {
            cows += min(cntS[i], cntG[i]);
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/bulls-and-cows/solution/cai-shu-zi-you-xi-by-leetcode-solution-q9lz/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。