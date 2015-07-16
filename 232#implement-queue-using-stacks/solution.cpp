class Queue {
public:
    stack<int> s, s2;
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(s2.empty()) {
            while (!s.empty()) {
                s2.push(s.top());
                s.pop();
            }
        }
        s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if(s2.empty()) {
            while (!s.empty()) {
                s2.push(s.top());
                s.pop();
            }
        }
        return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty() && s2.empty();
    }
};