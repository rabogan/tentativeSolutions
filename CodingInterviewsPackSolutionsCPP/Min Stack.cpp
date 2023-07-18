class MinStack {
    stack<int>data;
    stack<int>mnStack;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        data.push(val);
        if(mnStack.empty()||val<=mnStack.top())
            mnStack.push(val);
    }
    
    void pop() {
        if(mnStack.top()==data.top())
            mnStack.pop();
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mnStack.top();
    }
};
