#include<string>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Solution {
public:
    int maximumSwap(int num) {
        if(num<10)
            return num;
        string tmp = to_string(num);
        char t = tmp[0];
        int max = 0;
        for(int i=1;i<tmp.size();i++)
        {
            if(tmp[i]>=tmp[max])
                max = i;
        }     
        if(max!=0)
        {
            swap(tmp[max],tmp[0]);
            return atoi(tmp.c_str());
        }
        string ret ;
        ret.push_back(t);
        string temp;
        for(int i=1;i<tmp.size();i++)
            temp.push_back(tmp[i]);
        int next = atoi(temp.c_str());
        return atoi((ret+to_string(maximumSwap(next))).c_str());
    }
};