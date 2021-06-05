/*
    一个栈中元素的类型为整型，现在想将该栈从顶到底按从小到大的顺序排序，只许申请一个栈。
    除此之外，可以申请新的变量，但不能申请额外的数据结构。如何完成排序？
*/

#include<stack>
using namespace std;
void sort(stack<int>& A,stack<int>& help)
{
    if(A.empty())
        return;
    while(!A.empty())
    {
        int tmp = A.top();A.pop();
        if(help.empty())
        {
            help.push(tmp);
        }
        else
        {
            if(tmp>help.top())
            {
                help.push(tmp);
                continue;
            }
            else 
            {
                while(tmp<help.top())
                {
                    int key = help.top();help.pop();
                    A.push(key);
                    if(help.empty())
                    {
                        help.push(tmp);
                        break;
                    }
                    if(tmp>help.top())
                    {
                        help.push(tmp);
                    }
                }
            }
        }
    }
    while(!help.empty())
    {
        int tmp = help.top();help.pop();
        A.push(tmp);
    }
}