/*
    给定一个不含有重复值的数组arr，找到每一个i位置左边和右边离i最近的且值比arr[i]
    小的位置。返回所有位置相应的信息。
    arr = {3,4,1,5,6,2,7}
    返回如下二维数组作为结果：
{ 
 {-1, 2},
 { 0, 2},
 {-1,-1},
 { 2, 5},
 { 3, 5},
 { 2,-1},
 { 5,-1}
} 
    -1 表示不存在。所以上面的结果表示在 arr 中，0 位置左边和右边离 0 位置最近且值比 arr[0]
小的位置是-1 和 2；1 位置左边和右边离 1 位置最近且值比 arr[1]小的位置是 0 和 2；2 位置左
边和右边离 2 位置最近且值比 arr[2]小的位置是-1 和-1……
    进阶问题：给定一个可能含有重复值的数组 arr，找到每一个 i 位置左边和右边离 i 位置最
近且值比 arr[i]小的位置。返回所有位置相应的信息。
*/

/* O(N^2)算法 */
#include<vector>
#include<stack>
using namespace std;
vector<vector<int> >  rightWay(vector<int> arr)
{
    vector<vector<int> > ret;
    for(int i=0 ;i < arr.size() ;i++)
    {
        int tmp = arr[i];
        int left = -1;
        int right = -1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[j]<arr[i])
            {
                left = j;
                break;
            }
        }        
        for(int j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[i])
            {
                right = j;
                break;
            }
        }
        vector<int> t{left,right};
        ret.push_back(t);
    }
}

/* 单调栈方法 O（N）*/

vector<vector<int> > getNearLessNoRepeat(vector<int> arr)
{
    vector<vector<int> > ret (arr.size(),vector<int>(2));
    stack<int> monotonous_stack;
    for(int i = 0; i < arr.size(); i++)
    {
        while(!monotonous_stack.empty()&&arr[monotonous_stack.top()]>arr[i])
        {
            int popIndex = monotonous_stack.top();monotonous_stack.pop();
            int leftLessIndex = monotonous_stack.empty()?-1:monotonous_stack.top();
            ret[popIndex][0] = leftLessIndex;
            ret[popIndex][1] = i;
        }
        monotonous_stack.push(i);
    }
    while(!monotonous_stack.empty())
    {
        int popIndex = monotonous_stack.top();monotonous_stack.pop();
        int leftLessIndex = monotonous_stack.empty()?-1:monotonous_stack.top();
        ret[popIndex][0] = leftLessIndex;
        ret[popIndex][1] = -1;
    }
    return ret;
}

/* 进阶问题，可能含有重复值*/
