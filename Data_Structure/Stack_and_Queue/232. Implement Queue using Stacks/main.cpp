class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> A;
    stack<int> B;
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        A.push(x);
    }
    
    /** 先判断B是否为空呀！！细节 */
    int pop() {
        if(B.empty()) {
            while(!A.empty()) {
                int tmp = A.top();
                A.pop();
                B.push(tmp);
            }
        }
        int ans = B.top();
        B.pop();
        return ans;
    }
    
    /** Get the front element. */
    int peek() {
        if(B.empty()) {
            while(!A.empty()) {
                int tmp = A.top();
                A.pop();
                B.push(tmp);
            }
        }
        int ans = B.top();
        return ans;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return A.empty() && B.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */