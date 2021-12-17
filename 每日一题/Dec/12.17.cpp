class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ret = 0;
        if(numBottles%numExchange==0)
        {
            ret += numBottles;
            ret += numWaterBottles(numBottles/numExchange,numExchange);
            return ret;
        }
        else 
        {
            if(numBottles<numExchange)
            {
                ret += numBottles;
                return ret;
            }
            else 
            {
                ret += numBottles-numBottles%numExchange;
                ret += numWaterBottles(numBottles%numExchange+ret/numExchange,numExchange);
                return ret;
            }
        }
        return ret;
    }
};