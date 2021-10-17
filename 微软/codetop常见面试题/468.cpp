#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void split(string s,vector<string>& res,char delimiter,int delimitercnt)
    {
        int i = 0;
        int cnt  = 0;
        string temp;
        while(i < s.size())
        {
            if(s[i]!=delimiter)//不为分隔符加入
                temp.push_back(s[i]);
            if(s[i] == delimiter || i==s.size()-1)
            {
                if(temp.size() == 0)
                {
                    res.clear();
                    return;
                }
                if(s[i] == delimiter)//计算分隔符数
                    cnt++;
                if(cnt > delimitercnt)//分隔符数量多于限制
                {
                    res.clear();
                    return;
                }
                res.push_back(temp);
                temp.clear();
            }
            i++;           
        }
    }
    bool checkIPV4(string IP)
    {
        vector<string> res;
        split(IP,res,'.',3);
        if(res.size()!=4)//段数超长或超短
            return false;      
        for(int i=0;i<res.size();i++)
        {
            string temp = res[i];
            if(temp[0]=='0'&&temp.size()>1)//前导0
                return false;
            if(temp.size()>3)//段内超长
                return false;
            int num = 0;
            for(int j=0;j<temp.size();j++)
            {
                num = 10*num + temp[j]-'0';
                if(temp[j]<'0' || temp[j] > '9')
                    return false;
            }
            if(num > 255)//过大
                return false;
        }
        return true;
    }
    bool checkIPV6(string IP)
    {
        vector<string> res;
        split(IP,res,':',7);
        if(res.size()!=8)
            return false;
        for(int i = 0;i < res.size();i++)
        {
            string temp = res[i];
            if(temp.size() > 4)//段内超长
                return false;
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j]>='0'&&temp[j]<='9' || (temp[j]>='a' && temp[j]<='f') || (temp[j]>='A' && temp[j]<='F'))
                    continue;
                else 
                    return false;
            }
        }
        return true;
    }
    string validIPAddress(string IP) {
        if(checkIPV4(IP))
            return "IPv4";
        if(checkIPV6(IP))
            return "IPv6";
        return "Neither";
    }
};