#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> left;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='*')
            {
                left.push(s[i]);
            }
            else if(s[i]==')')
            {
                if(left.empty())
                {
                    return false;
                }
                stack<char> tmp;
                while(!left.empty()&&left.top()=='*')
                {
                    char t = left.top();
                    tmp.push(t);
                    left.pop();
                }
                if(left.empty())
                {
                    //这个时候并没有左括号，用*代替
                    tmp.pop();
                    left = tmp;
                }
                else 
                {
                    left.pop();
                    while(!tmp.empty())
                    {
                        left.push(tmp.top());
                        tmp.pop();
                    }
                }
            }
        }
        stack<char> tmp;
        while(!left.empty())
        {
            if(left.top()=='(')
            {
                if(tmp.empty())
                {
                    return false;
                }
                else 
                {
                    left.pop();
                    tmp.pop();
                }
            }
            else 
            {
                tmp.push('*');
                left.pop();
            }
        }
        return true;
    }
};