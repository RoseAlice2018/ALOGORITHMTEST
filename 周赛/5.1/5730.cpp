#include <string>
using namespace std;
class Solution {
public:
    char shift(char c,int x)
    {
        return c+x;
    }
    string replaceDigits(string s) {
        if(s.size()<1)
            return s;
        for(int i=1;i<s.size();i+=2)
        {
            char temp = shift(s[i-1],s[i]-'0');
            s[i]=temp;
        }
        return s;
    }
};