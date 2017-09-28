//
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.
//
//


class MinStack {
private:
    stack<int> s1, s2;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    //使用两个栈，s1存整个push到栈中的数据，s2总是push截止到当前为止出现的最小值
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=s2.top())
            s2.push(x);
    }
    
    void pop() {
        if(s1.top()==s2.top())
            s2.pop();
        //注意这里s1.pop()一定需要放在s2是否弹出的后面，顺序不能换，换了就是先已经弹出了s1的一个值，之后接着用已经弹出的s1的top和s2.top比较，效果不一样
        s1.pop();
    }
    
    int top() {
        return s1.top();    
    }
    
    int getMin() {
        return s2.top();
    }
   
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
