/*
给定整数 N，返回斐波那契数列的第 N 项。
补充问题 1：给定整数 N，代表台阶数，一次可以跨 2 个或者 1 个台阶，返回有多少种走
法
*/
//递归
int fibnacci(int N)
{
    if(N==1)
        return 1;
    else if(N==2)
        return 1;
    else 
        return fibnacci(N-1)+fibnacci(N-2);
}
//动态规划
int fibnacci(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 1;
    int f1=1,f2=1;
    while(n>2)
    {
        int tmp = f1 + f2;
        f1 = f2;
        f2 = tmp;
        n--;
    }
    return f2;
}

//台阶

//递归
int floor(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    else 
        return floor(n-2)+floor(n-1);
}
//动态规划
int floor(int n)
{
    if(n==1)
        return 1;
    else if(n==2)
        return 2;
    int f1=1,f2=2;
    while(n>2)
    {
        int tmp = f1 + f2;
        f1 =  f2;
        f2 = tmp;
        n--;
    }
    return f2;
}