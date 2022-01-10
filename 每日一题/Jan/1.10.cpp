#include <string>
#include <stdlib.h>
using namespace std;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        int firststart = 0;
        int firstend   = 0;
        int secondstart = firstend+1;
        int secondend   = secondstart;
        for(;firstend<n;firstend++)
        {
            int firstdata = toInt(num,firststart,firstend);
            secondstart = firstend+1;
            if(num[secondstart]=='0')
            {
                continue;
            }
            for(;secondend<n;secondend++)
            {
                int secondata = toInt(num,secondstart,secondend);
                for(int i = secondend +1 ;i<n;i++)
                {
                    int thirddata = toInt(num,secondend+1,i);
                    if(secondata+ firstdata == thirddata)
                    {
                        firstdata = secondata;
                        secondata = thirddata;
                        
                    }
                    else 
                    {
                        continue;
                    }
                }
            }
        }
    }
    int toInt(string num,int begin,int end)
    {
        int ret = 0;
        for(int i =  begin;i<=end;i++)
        {
            ret = (ret * 10)+num[i]-'0';
        }
        return ret;
    }
};