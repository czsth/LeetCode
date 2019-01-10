class MinStack {
    vector<int> _s;
    int mn;
    int mnCnt;
    
    void findmn() {
        mnCnt = 0;
        int tmpr = 0;
        for (int i = 1; i < _s.size() - 1; ++i) {
            if (_s[i] < _s[tmpr]) tmpr = i;
        }
        mn = _s[tmpr];
        for (int i = 0; i < _s.size() - 1; ++i) {
            if (_s[i] == mn) ++mnCnt;
        }
    }
public:
    /** initialize your data structure here. */
    MinStack() {
        _s.clear();
        mnCnt = 0;
    }
    
    void push(int x) {
        _s.push_back(x);
        if (_s.size() == 1) {
            mn = _s[0];
            mnCnt = 1;
        }
        else {
            if (x == mn) ++mnCnt;
            mn = min(mn, x);
        }
    }
    
    void pop() {
        if (!_s.size()) return;
        if (_s[_s.size() - 1] == mn) {
            if (!--mnCnt) findmn();
        }
        _s.erase(--_s.end());
    }
    
    int top() {
        return _s[_s.size() - 1];
    }
    
    int getMin() {
        return mn;
    }
};

//赖一点，也是24 ms
class MinStack {
public:
    stack<int> s;
    stack<int> mins;    //此处很微妙
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (mins.empty() || mins.top() >= x) {
            mins.push(x);
        }
    }
    
    void pop() {
        if (s.top() == mins.top()) {
            mins.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
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