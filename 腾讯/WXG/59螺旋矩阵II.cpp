#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> >matrix(n,vector<int>(n));
        int up = 0;
        int left = 0;
        int right = n-1;
        int bottom = n-1;
        int num = 1;
        while(num<=n*n)
        {
            for(int column = left;column<=right;column++)
            {
                matrix[up][column] = num;
                num++;
            } 
            for(int row = up+1;row <= bottom; row++)
            {
                matrix[row][right] = num;
                num++;
            }
            if (left < right && up < bottom)
            {
                for(int column = right-1 ; column > left ; column--)
                {
                    matrix[bottom][column] = num;
                    num++;
                }         
                for(int row = bottom;row>up;row--)
                {
                    matrix[row][left] = num;
                    num++;
                }
            }
            up++;
            right--;
            left++;
            bottom--;
        }
        return matrix;
    }
};