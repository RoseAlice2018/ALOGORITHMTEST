#include<string>
using namespace std;
class Solution {
public:
    int getLucky(string s, int k) {
        string first = chartoint(s);
        for(int i=1;i<k;i++)
        {
            first = add(first);  
        }
        int ret = addtoint(first);
        return ret;
    }
    string chartoint(string s)
    {
        string ret = "";
        for(int i=0;i<s.size();i++)
        {
            int tmp = s[i]-'a' + 1;
            if(tmp<0)
                ret.push_back(tmp+'0');
            else 
            {
                int t = (tmp-tmp%10)/10;
                ret.push_back(t+'0');
                ret.push_back(tmp%10+'0');
            }
        }
        return ret;
    }
    string add(string s)
    {
        int ret = addtoint(s);
        string res = to_string(ret);
        return res;
    }
    int addtoint(string s)
    {
        int ret =0 ;
        for(int i=0;i<s.size();i++)
        {
            char tmp = s[i];
            ret += tmp-'0';
        }
        return ret;
    }
};