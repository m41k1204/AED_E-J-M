class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        queue<int> q;
        for (int num : popped) {
            q.push(num);
        }
        for (int i = 0; i < pushed.size(); i++) {
            st.push(pushed[i]);
            while( !st.empty() && st.top() == q.front()) {
                st.pop();
                q.pop();
            }
        }
        return st.empty();

    }
};
