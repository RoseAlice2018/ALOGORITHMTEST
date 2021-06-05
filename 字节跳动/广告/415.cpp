#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) {
        int beginA = num1.size()-1;
        int beginB = num2.size()-1;
        string ret;
        int add = 0;
        while(beginA>=0&&beginB>=0)
        {
            int A = num1[beginA]-'0';
            int B = num2[beginB]-'0';
            int sum = A + B + add;
            if(sum < 10)
            {
                ret.push_back(sum+'0');   
                add = 0;
            }
            else 
            {
                ret.push_back(sum - 10 +'0');
                add = 1;
            }
            beginA--;
            beginB--;
        }
        while(beginA>=0)
        {
            int A = num1[beginA]-'0'+add;
            if(A<10)
            {
                ret.push_back(A+'0');   
                add = 0;   
            }
            else if(A>=10)
            {
                ret.push_back(A - 10 +'0');
                add = 1;    
            }
            beginA--;
        }
         while(beginB>=0)
        {
            int B = num2[beginB]-'0'+add;
            if(B<10)
            {
                ret.push_back(B+'0');   
                add = 0;   
            }
            else if(B>=10)
            {
                ret.push_back(B - 10 +'0');
                add = 1;    
            }
            beginB--;
        }
        if(add>0)
            ret.push_back(add+'0');
        reverse(ret.begin(),ret.end());
        return ret;
    }
};