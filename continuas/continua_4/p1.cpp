class MyStack {
private:
    queue<int> q1;
public:
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int sz = q1.size();
        int top = 0;
        while (sz != 0) {
            int size = sz - 1;
            if (size == 0) {
                top = q1.front();
                q1.pop();
                return top;
            }
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
            --sz; 
        }

        return top;
    }
    
    int top() {
       return q1.back(); 
    }
    
    bool empty() {
        return q1.empty();
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
