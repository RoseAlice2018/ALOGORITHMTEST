#include<vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
        else{
            vector<int> tmp;
            while(x!=0)
            {
                int t = x%10;
                tmp.push_back(t);
                x=(x-t)/10;
            }
            int left=0,right=tmp.size()-1;
            while(left<=right)
            {
                if(tmp[left]!=tmp[right])
                    return false;
                left++;
                right--;
            }
            return true;
        }
        return true;
    }
};