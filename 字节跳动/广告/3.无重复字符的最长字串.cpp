#include<string>
#include<set>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0,right=0;
        int ret = 0;
        set<char> dic;
        while(right<s.size())
        {
            char tmp = s[right];
            if(dic.count(tmp))
            {
                while(dic.count(tmp))
                {
                    dic.erase(s[left]);
                    left++;
                }
                dic.insert(s[right]);
            }
            else 
            {
                dic.insert(tmp);
                if(dic.size()>ret)
                    ret = dic.size();
            }
            right++;
        }
        return ret;
    }
};