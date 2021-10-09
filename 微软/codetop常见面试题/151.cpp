#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> ret;
        int flag = 0;//0 " " 1 "word"
        string tmp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(flag)
                {
                    ret.push_back(tmp);
                    tmp.clear();
                    flag=0;
                }
                continue;
            }
            else{
                flag = 1;
                tmp.push_back(s[i]);
            }           
        }
        if(!tmp.empty())
        ret.push_back(tmp);
        string res;
        for(int i=0;i<ret.size();i++)
        {
           // cout<<i<<":"<<ret[i]<<endl;
            if(i==0)
            {
                res+=ret[ret.size()-1-i];
            }             
            else 
            {
                res.push_back(' ');
                res+=ret[ret.size()-1-i];
            }
        }
        return res;
    }
};
