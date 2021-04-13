class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A;
    stack<int> C;
    MinStack() {

    }
    void push(int val) {
        C.push(val);
        if(A.empty()) {
            A.push(val);    
        }
        else {
            if(val > A.top()) {
                stack<int> B;
                while(!A.empty() && val > A.top()) {
                    int tmp = A.top();
                    A.pop();
                    B.push(tmp);
                }
                A.push(val);
                while(!B.empty()) {
                    int tmp = B.top();
                    B.pop();
                    A.push(tmp);
                }
            }
            else A.push(val);
        }
    }
    
    void pop() {
        stack<int> B;
        while(A.top() != C.top()){
            int tmp = A.top();
            A.pop();
            B.push(tmp);
        }
        C.pop();
        A.pop();
        while(!B.empty()){
            int tmp = B.top();
            B.pop();
            A.push(tmp);
        }
    }
    
    int top() {
        return C.top();
    }
    
    int getMin() {
        int min = A.top();
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */