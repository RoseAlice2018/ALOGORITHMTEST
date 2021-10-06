#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

void addtwo(int a[3],int b[2],int res[12])
{
    vector<int> c;
    int begin = 0;
    int end = 4;
    //sort
    for(int i=0;i<3;i++)
        c.push_back(a[i]);
    for(int i=0;i<2;i++)
        c.push_back(b[i]);
    sort(c.begin(),c.end());
    int head=0,tail=1;
    int count=0;
    while(tail<c.size())
    {
        count++;
        int low = c[head];
        int high = c[tail];
        res[begin]=high;
        res[end] = low;
        head=tail+1;
        tail=head+1;
        begin++;
        end--;
    }
    if(head<c.size()&&tail==c.size())
    {
        res[begin]=c[head];
    }
}

int main()
{
    int a[3]={5,10,15};
    int b[2]={20,40};
    int res[12];
    addtwo(a,b,res);
    for(int i=0;i<5;i++)
    {
        cout<<res[i]<<endl;
    }
}