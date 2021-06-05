#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size()-1;
        int n = 0;
        while(m>=0&&n<=matrix[0].size()-1)
        {
            if(matrix[m][n]==target)
                return true;
            else if(matrix[m][n]>target)
            {
                m--;
            }
            else if(matrix[m][n]<target)
            {
                n++;
            }
        }   
        return false;     
    }
};