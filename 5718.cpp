#include<vector>
#include<set>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> countPoints(vector<vector<int> >& points, vector<vector<int> >& queries) {
        vector<int> ans;
        map<int,set<int> > dic;
        for(int i=0 ;i< points.size();i++)
        {
            int xi = points[i][0];
            int yi = points[i][1];
            if(dic.count(xi))//xi 进入
            {
                dic[xi].insert(yi);
            }
            else 
            {
                set<int> t;t.insert(yi);
                dic[xi] = t;
            }
        }
        for(int i = 0;i<queries.size();i++)
        {
            int ret = 0;
            for(auto iter = dic.begin();iter!=dic.end();iter++)
            {
                int xi =iter->first;
                for(auto itt = dic[xi].begin();itt!=dic[xi].end();itt++)
                {
                    int yi = &itt;
                    if()
                }
                
            }
        }
        return ans;
    }
};