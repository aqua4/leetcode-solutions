class MinStack {
private:
    stack<int> st;
    stack<int> s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (s.empty() || x<=s.top()) s.push(x);
    }
    
    void pop() {
        if (st.top()==s.top()) s.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return s.top();
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