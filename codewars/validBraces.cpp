#include<stack>
#include<string>
using namespace std;
bool valid_braces(std::string braces)
{
    //valid or not valid
    stack<char> brace;
    for(int i=0;i<braces.size();i++)
    {
        if(braces[i]=='('||braces[i]=='{'||braces[i]=='[')
            brace.push(braces[i]);
        else 
        {
            char c = brace.top();
            if(c=='('&&braces[i]==')')
                brace.pop();
            else if(c=='['&&braces[i]==']')
                brace.pop();
            else if(c=='{'&&braces[i]=='}')
                brace.pop();
            else 
                return false;
        }        
    }
    if(brace.empty())
        return true;
    return false;
}