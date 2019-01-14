//最后看到评论区说用一个队列
//将队首元素放到队尾就可以
//很有道理
//但是就不再再做一次了，这个题感觉一般般
class MyStack {
    queue<int> qa, qb;
    queue<int> *curr, *assist;
public:
    /** Initialize your data structure here. */
    MyStack() {
        curr = &qa;
        assist = &qb;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        curr->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (curr->size() > 1) {
            assist->push(curr->front());
            curr->pop();
        }
        int x = curr->front();
        curr->pop();
        queue<int> *tmp = curr;
        curr = assist;
        assist = tmp;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        while (curr->size() > 1) {
            assist->push(curr->front());
            curr->pop();
        }
        int x = curr->front();
        assist->push(curr->front());
        curr->pop();
        queue<int> *tmp = curr;
        curr = assist;
        assist = tmp;
        return x;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return curr->empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */