#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ret;
        int up = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        int count = 0;
        while(count<matrix[0].size()*matrix.size())
        {
            for(int column = left;column<=right;column++)
            {
                ret.push_back(matrix[up][column]);
                count++;
            }
            for(int row = up+1;row<=bottom;row++)
            {
                ret.push_back(matrix[row][right]);
                count++;
            }
            if(left<right&&up<bottom)
            {
                for(int column = right -1;column>=left;column--)
                {
                    ret.push_back(matrix[bottom][column]);
                    count++;
                }
                for(int row = bottom -1;row>up;row--)
                {
                    ret.push_back(matrix[row][left]);
                    count++;
                }
            }
            left++;
            right--;
            up++;
            bottom--;
        }
        return ret;
    }
};