#include<stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int val) {
        num.push(val);
        if(min.empty())
            min.push(val);
        else 
        {
            if(val<min.top())
                min.push(val);
            else 
                min.push(min.top());
        }
    }
    
    void pop() {
        min.pop();
        num.pop();
    }
    
    int top() {
        return num.top();
    }
    
    int getMin() {
        return min.top();
    }
    stack<int> num;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */