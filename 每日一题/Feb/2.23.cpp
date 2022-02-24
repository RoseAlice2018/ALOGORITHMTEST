#include <string>
using namespace std;
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left_point = 0;
        int right_point = s.size()-1;
        while(left_point<=right_point)
        {
            int left=-1;
            for(int i=left_point;i<=right_point;i++)
            {
                if(isalpha(s[i]))
                {
                    left = i;
                    break;
                }
            }
            int right = -1;
            for(int i= right_point;i>=left_point;i--)
            {
                if(isalpha(s[i]))
                {
                    right = i;
                    break;
                }
            }
            if(left!=-1&&right!=-1)
            {
                swap(s[left],s[right]);
                left_point = left + 1;
                right_point = right - 1;
            }
            else{
                break;
            }
        }
        return s;  
    }
};