/*
    一个栈依次压入1，2，3，4，5，那么从栈顶到栈底分别为5，4，3，2，1.将这个栈转置
    后，从栈顶到栈底为1，2，3，4，5.也就是实现栈中元素的逆序，但是只能用递归函数来实现
    不能用其他数据结构。
*/

#include <stack>
using namespace std;


int getAndRemoveLastElemet(stack<int>& val_stack)
{
    int result = val_stack.top();val_stack.pop();
    if(val_stack.empty())
    {
        return result;
    }
    else 
    {
        int last = getAndRemoveLastElemet(val_stack);
        val_stack.push(result);
        return last;
    }
}

void reverse(stack<int>& val_stack)
{
    if(val_stack.empty())
    {
        return;
    }
    int i = getAndRemoveLastElemet(val_stack);
    reverse(val_stack);
    val_stack.push(i);
}