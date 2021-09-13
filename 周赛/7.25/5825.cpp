#include<string>
#include<deque>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        s = back(s);
        t = back(t);
        if(s.size()!=t.size())
            return false;
        else 
        {
            for(int i=0;i<s.size();i++)
            {
                if(s[i]!=t[i])
                    return false;
            }
        }
        return true;
    }
    string back(string s)
    {
        string ret;
        deque<char> tmp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#')
            {
                if(tmp.size()>=1)
                {
                    tmp.pop_back();           
                }
                else 
                    ;
            }
            else 
                tmp.push_back(s[i]);
        }
        for(int i=0;i<tmp.size();i++)
        {
            char t = tmp.front();tmp.pop_front();
            ret.push_back(t);
        }
        return ret;
    }
};