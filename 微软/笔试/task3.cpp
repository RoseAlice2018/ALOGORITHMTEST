#include<vector>
using namespace std;
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int B[A.size()+2];
    int right_point = A.size()-1;
    int min = A[right_point];
    B[right_point] = min;
    B[right_point+1]=1000000001;
    while(right_point>=0)
    {
        if(A[right_point]<min)
        {
           min = A[right_point];
        }
        B[right_point]=min;
        right_point--;
    }
    int ret = 0;
    int tmp_max = 0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>tmp_max)
        {
            tmp_max = A[i];
        }
        if(tmp_max<B[i+1])
        {
            ret++;
        }
    }
    return ret;
}
