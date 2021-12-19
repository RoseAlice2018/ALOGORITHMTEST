#include<vector>
#include<map>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int> >& trust) {
        vector<vector<int> > dir(n+2,vector<int>(n+2));
        for(int i=0;i<trust.size();i++)
        {
            int a = trust[i][0];
            int b = trust[i][1];
            dir[a][b] = 1;
        }
        for(int i=1;i<=n;i++)
        {
            //if he trust nobody condition1
            int j;
            for( j=1;j<=n;j++)
            {
                if(dir[i][j]==1)
                    break;
            }
            if(j==n+1)//satisfy condition1
            {
                int k;
                for(k=1;k<=n;k++)
                {
                    if(dir[k][i]==0&&k!=i)
                        break;
                }
                if(k==n+1)
                    return i;
            }
        }
        return -1;
    }
};