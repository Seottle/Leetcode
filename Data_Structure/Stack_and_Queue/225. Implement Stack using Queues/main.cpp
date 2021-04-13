class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> Q1;
    queue<int> Q2;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q1.push(x);
        while(!Q2.empty()) {
            int tmp = Q2.front();
            Q2.pop();
            Q1.push(tmp);
        }
        while(!Q1.empty()) {
            int tmp = Q1.front();
            Q1.pop();
            Q2.push(tmp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = Q2.front();
        Q2.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        int tmp = Q2.front();
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */