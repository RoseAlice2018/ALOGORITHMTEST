#include <vector>
using namespace std;
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxLen=0;
        int ret = 0;
        for(int i=0;i<rectangles.size();i++)
        {
            if(min(rectangles[i][0],rectangles[i][1])>maxLen)
            {
                maxLen = min(rectangles[i][0],rectangles[i][1]);
                ret = 1;
            }
            else if(min(rectangles[i][0],rectangles[i][1])==maxLen)
            {
                ret++;
            }
        }
        return ret;
    }
};