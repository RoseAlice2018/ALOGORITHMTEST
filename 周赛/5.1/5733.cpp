#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    //按房间size排序
    bool first(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    vector<int> closestRoom(vector<vector<int> >& rooms, vector<vector<int> >& queries) {
        sort(rooms.begin(),rooms.end(),first);
        
    }
};