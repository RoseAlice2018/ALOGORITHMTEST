#include<string>
using namespace std;
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ret;
        for(int i=0;i<s.size();i++)
        {
            string tmp;
            while(s[i]!=' '&&i<s.size())
            {
                tmp.push_back(s[i]);
                i++;
            }
            ret.append(tmp);
            k--;
            if(k==0)
                return ret;
            else 
                ret.push_back(' ');
        }
        return ret;
    }
};