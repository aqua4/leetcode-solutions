class MinStack {
private:
    stack<int> st;
    int mi = INT_MAX;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        mi = min(mi,x);
    }
    
    void pop() {
        if (st.top()==mi) {
            st.pop();
            stack<int> s;
            mi = INT_MAX;
            while (!st.empty()) {
                mi=min(mi,st.top());
                s.push(st.top());
                st.pop();
            }
            while (!s.empty()) {
                st.push(s.top());
                s.pop();
            }
        } else st.pop();    
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mi;
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