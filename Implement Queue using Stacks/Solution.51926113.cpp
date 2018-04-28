class Queue {
public:
    stack<int> s,t;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        t.pop();
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        while(!s.empty()) {
            t.push(s.top());
            s.pop();
        }
        int x=t.top();
        while(!t.empty()) {
            s.push(t.top());
            t.pop();
        }
        return x;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
};