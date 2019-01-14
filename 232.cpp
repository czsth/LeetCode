//那些拿vector实现的真的赖
class MyQueue {
    stack<int> sin, sout;
    int state;  //0 for input, 1 for output
    
    void toInput() {
        if (state == 0) return;
        state = 0;
        while (!sout.empty()) {
            sin.push(sout.top());
            sout.pop();
        }
    }
    
    void toOutput() {
        if (state == 1) return;
        state = 1;
        while (!sin.empty()) {
            sout.push(sin.top());
            sin.pop();
        }
    }
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        toInput();
        sin.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        toOutput();
        int x = sout.top();
        sout.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        toOutput();
        int x = sout.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return sin.empty() && sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */