class Solution {
public:
    int addOnce(int num)
    {
        int ret=0;
        while(num>0)
        {
            ret += num%10;
            num = (num-num%10)/10;
        }
        return ret;
    }
    int addDigits(int num) {
        while(num>=10)
        {
            num = addOnce(num);
        }
        return num;
    }
};