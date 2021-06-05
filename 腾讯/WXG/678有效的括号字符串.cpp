#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> left;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                left.push('(');
            else 
            {
                if(left.empty())
                    return false;
                else 
                    left.pop();
            }
        }
        return left.empty();
    }
    bool checkValidString(string s) {
        
    }
};