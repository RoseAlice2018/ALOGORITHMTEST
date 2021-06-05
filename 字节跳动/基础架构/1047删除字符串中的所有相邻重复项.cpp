#include <string>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for(int i=0;i<s.size();)
        {
            int begin = i;
            int next = i+1;
            while(s[begin]==s[next])
            {
                //执行删除操作
                s[begin]='0';
                s[next]='0';
                begin = begin -1;
                next = next + 1;
                if(begin<0&&next<s.size()-1)
                {
                    begin = next;
                    next++;
                }
                // else if(begin>0&&next>=s.size())
                // {
                //     next = begin;
                //     --begin;
                // }
                else if(begin<0||next>=s.size())
                    break;
            }    
            i = next;
        }
        for(int i=0;i<s.size();i++)
            if(s[i]!='0')
                res.push_back(s[i]);
        return res;
    }
};