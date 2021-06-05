#include<string>
using namespace std;
class Solution {
public:
    string add(string num1,string num2)
    {
        int index1=num1.size()-1;
        int index2=num2.size()-1;
        int flag = 0;
        string ret;
        while(index1>=0&&index2>=0)
        {
            int add_val = num1[index1]-'0'+num2[index2]-'0'+flag;
            if(add_val<10)
            {
                ret.push_back(add_val+'0');
                flag=0;
            }
            else 
            {
                int tmp = add_val-10;
                flag=1;
                ret.push_back(tmp+'0');
            }
            index1--;
            index2--;
        }
        while(index1>=0)
        {
            int add_val = num1[index1]-'0' + flag;
            if(add_val<10)
            {
                flag=0;
                ret.push_back(add_val+'0');
            }
            else 
            {
                add_val = add_val-10;
                flag=1;
                ret.push_back(add_val+'0');
            }
            index1--;
        }
        while(index2>=0)
        {
            int add_val = num2[index2]-'0' + flag;
            if(add_val<10)
            {
                flag=0;
                ret.push_back(add_val+'0');
            }
            else 
            {
                add_val = add_val-10;
                flag=1;
                ret.push_back(add_val+'0');
            }
            index2--;
        }
        if(flag==1)
        {
            ret.push_back('1');
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        string ret = "0";
        int index1=num1.size()-1;
        while(index1>=0)
        {
            //mul
            int index2=num2.size()-1;
            string tmp;
            int flag = 0;
            while(index2>=0)
            {
                int mul = (num1[index1]-'0')*(num2[index2]-'0')+flag;
                if(mul<10)
                {
                    flag=0;
                    tmp.push_back(mul+'0');
                }
                else 
                {
                    int t = mul%10;
                    flag = (mul-t)/10;
                    tmp.push_back(t+'0');
                }
                index2--;
            }
            if(flag>0)
                tmp.push_back(flag+'0');
            reverse(tmp.begin(),tmp.end());
            for(int i=index1;i<num1.size()-1;i++)
                tmp.push_back('0');
            ret = add(tmp,ret);
            index1--;
        }
        if(ret[0]=='0')
            return "0";
        return ret;
    }
};