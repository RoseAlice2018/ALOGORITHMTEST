/*
给定数组 arr，arr 中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值
的货币可以使用任意张，再给定一个整数 aim，代表要找的钱数，求组成 aim 的最少货币数

arr=[5,2,3]，aim=20。 4 张 5 元可以组成 20 元，其他的找钱方案都要使用更多张的货币，所以返回 4。
arr=[5,2,3]，aim=0。
不用任何货币就可以组成 0 元，返回 0。
arr=[3,5]，aim=2。
根本无法组成 2 元，钱不能找开的情况下默认返回-1。
*/
#include<vector>
using namespace std;
int mainCoins(vector<int> arr,int aim)
{
    if(arr.size()==0||aim < 0)
    {
        return -1;
    }
    return process(arr,0,aim);
}

int process(vector<int> arr,int i,int rest)
{
    //base case
    //已经没有面置能够考虑了
    //如果此时剩余的钱为0，返回0张
    //如果此时剩余的钱不是0.返回-1
    if (i == arr.size())
    {
        return rest == 0 ? 0 : -1;
    }
    //最少张数，初始为-1，因为还没找到有效解
    int res = -1;
    //依次尝试使用当前面置(arr[i]0,1,k,但不能超过rest)
    for (int k = 0;k * arr[i] <= rest;k++)
    {
        //使用了K张arr[i]
        int next = process(arr,i+1,rest-k*arr[i]);
        if(next!=-1)
        {
            res = res==-1?next+k:min(res,next+k);
        }
    }
    return res;
}

