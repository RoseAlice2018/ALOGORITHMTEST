/*
给定一个矩阵 m，从左上角开始每次只能向右或者向下走，最后到达右下角的位置，路径
上所有的数字累加起来就是路径和，返回所有的路径中最小的路径和。
*/
#include<vector>
using namespace std;
int matrix_min(vector<vector<int> > matrix)
{
    int sum = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int> > dp(m,vector<int>(n));
    dp[0][0] = matrix[0][0];
    for(int i=1;i<n;i++)
        dp[0][i] = dp[0][i-1]+matrix[0][i];
    for(int j=1;j<m;j++)
        dp[j][0] = dp[j-1][0]+matrix[j][0];
    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
        }
    }
    return dp[m-1][n-1];
}

/*
    压缩数组
*/