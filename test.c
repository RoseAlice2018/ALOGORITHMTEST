#include<stdio.h>
int main()
{
    int a[2][3] = {2,4,6,8,10,12};
    printf("a[0][0] %d\n",*(&a[0][0]));
    printf("a %d\n",*(&a));
    printf("a[0] %d\n",*(&a[0]));
    printf("a[1] %d\n",*(&a[1]));
    return 0;
}