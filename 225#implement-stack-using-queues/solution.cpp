class Stack {
public:
    int l = 0;
    queue<int> p;
    // Push element x onto stack.
    void push(int x) {
        p.push(x);
        for(int i = 0; i < l; i++) {
            p.push(p.front());
            p.pop();
        }
        l++;
    }

    // Removes the element on top of the stack.
    void pop() {
        p.pop();
        l--;
    }

    // Get the top element.
    int top() {
        return p.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return p.empty();
    }
};