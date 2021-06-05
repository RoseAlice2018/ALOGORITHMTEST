/*
    实现一个特殊的栈，在实现栈的基本功能的基础上，再实现返回栈的最小元素的操作。
*/

/*
    要求：
        1. pop push getMin 操作的时间复杂度都是O(1)
        2. 设计栈可以使用现成的栈架构
*/
#include<stack>
using namespace std;

template <typename T>
class MinStack{
    MinStack(){};
    ~MinStack(){};

    //push
    void push(T val)
    {
        tmp.push(val);
        if(min.empty())
        {
            min.push(val);
            return;
        }
        if(min.top()<val)
        {
            min.push(min.top());
            return;
        }
        else
        {
            min.push(val);
        }
    }
    //pop
    void pop()
    {
        tmp.pop();
        min.pop();
    }
    //getMin
    void getMin()
    {
        return min.top();
    }
    private:
        stack<T> min;
        stack<T> tmp; 
};
/*
    时间复杂度为O(1)
    空间复杂度为O(n)
*/