class MyQueue {
private:
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int sz = st1.size();
        cout << sz << " ";
        int top = 0;
        while (sz != 0) {
            int size = sz -1;
            if (size == 0) {
                top = st1.top();
                st1.pop();
                sz--;
            } else {
                st2.push(st1.top());
                st1.pop();
                sz--;
            }
        }
        sz = st2.size();
        cout << sz << " ";
        while (sz != 0) {
            st1.push(st2.top());
            st2.pop();
            sz--;
        }
        
        return top;
    }
    
    int peek() {
        int sz = st1.size();
        while (sz != 0) {
            st2.push(st1.top());
            st1.pop();
            sz--;
        }
        int top = st2.top();
        sz = st2.size();

        while (sz != 0) {
            st1.push(st2.top());
            st2.pop();
            sz--;
        }

        return top;
    }
    
    bool empty() {
        return st1.empty();
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
