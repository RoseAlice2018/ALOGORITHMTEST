class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        int index_row = m;
        int index_column = 0;
        while(index_row>=0&&index_column<=n)
        {
            if(matrix[index_row][index_column]==target)
                return true;
            else if(matrix[index_row][index_column]>target)
            {
                index_row--;
            }
            else 
            {
                index_column++;
            }
        }      
        return false;
    }
};