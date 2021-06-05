// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
#include<vector>
using namespace std;
int rand7();
class Solution {
public:
    int rand10() {
        int i = rand7();
        int j = rand7();
        while(i>6||(i==6&&j>=6))
        {
            i=rand7();
            j=rand7();
        }
        int idx=(i-1)*7+j;
        return 1+(idx-1)%10;
    }
};