#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int up_limit = __INT_MAX__;
    int down_limit = -up_limit-1;
    int myAtoi(string s) {
        long ret = 0;
        int flag=1;//1 未遇到第一个非空或0的数字
        int flag_symbol=0;//0 + 1 -
        for(int i =0;i<s.size();i++)
        {
            while(flag)
            {
                //读入字符串丢弃无用的空格
                while(s[i]==' ')
                    i++;
                //检查下一个字符
                if(i>=s.size())
                    break;
                if(s[i]=='+')
                {
                    flag_symbol=0;
                    i++;
                }
                else if(s[i]=='-')
                {
                    flag_symbol=1;
                    i++;
                }
                if(s[i]>='0'&&s[i]<='9')
                {
                    flag = 0;
                    break;
                }
                else 
                    return 0;
                i++;
            }
            if(s[i]>='0'&&s[i]<='9')
            {
                 int tmp = s[i]-'0';
                 if(ret>up_limit/10)
                  {  ret = flag_symbol?down_limit:up_limit;
                    break;
                  }
                 ret = (ret*10)+tmp;
            }
            else 
                break;
        }
        if(flag_symbol)
        {
            //负号
            if(-ret<down_limit)
            {
                ret = down_limit;
                return ret;
            }
            else 
                return -ret;
        }
        if(ret>up_limit)
            return up_limit;
        else 
            return ret;        
    }
};