/*
    编写一个类，用两个栈实现队列，支持队列的基本操作（push，pop，top）
*/

#include <stack>
using namespace std;

template <class T>
class queue
{
    queue(){};
    ~queue(){};

    //push
    void push(T val)
    {
        num1.push(val);
    }    
    //pop
    void pop()
    {
        if(num2.empty())
        {
            while(!num1.empty())
            {
                T tmp = num1.top();
                num1.pop();
                num2.push(tmp);
            }
            num2.pop();
        }
        else 
            num2.pop();
    }
    //top
    T top()
    {
        if(num2.empty())
        {
            while(!num2.empty())
            {
                T tmp = num1.top();
                num1.pop();
                num2.push(tmp);
            }
            return num2.top();
        }
        else 
            return num2.top();
    }
    private:
        stack<T> num1;
        stack<T> num2;
};