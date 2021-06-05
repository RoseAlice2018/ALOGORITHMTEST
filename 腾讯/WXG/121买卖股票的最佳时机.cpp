#include<vector>
using namespace  std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret  = 0;
        int min = prices[0];
        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]>min)
            {
                ret=max(ret,(prices[i]-min));
            }
            else if(prices[i]<min)
                min = prices[i];
        }
        return ret;
    }
};