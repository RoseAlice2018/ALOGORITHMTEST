//递归
#include<iostream>
using namespace std;
int goGridRecursion(int size)
{
    //边界条件 输入为负数 不合法
    if(size<0)
        return -1;
    //小于等于2 如果只有一个格子，只有一种走法，如果只有两个格子 两种走法。
    else if(size<=2)
        return size;
    else 
        return goGridRecursion(size-1)+goGridRecursion(size-2);
}
int goGrid(int size)
{
    int Grid_Two = 1,Grid_One =  2;
    if(size<0)
        return -1;
    else if(size<=2)
        return size;
    else 
    {
        while(size>2)
        {
            int temp=Grid_One+Grid_Two;
            Grid_Two = Grid_One;
            Grid_One = temp;
            size--;
        }

        return Grid_One;
    }
}
int main()
{
    int size;
    cin>>size;
    cout<<"Recursion"<<goGridRecursion(size)<<endl;
    cout<<"Iteration"<<goGrid(size)<<endl;
    return 0;
}
