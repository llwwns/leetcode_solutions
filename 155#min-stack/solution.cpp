class MinStack {
    stack<int> arr, min;
public:
    MinStack() {
        arr.push(0);
        min.push(2147483647);
    }
    void push(int x) {
        min.push(min.top() < x ? min.top() : x);
        arr.push(x);
    }

    void pop() {
        arr.pop();
        min.pop();
    }

    int top() {
        return arr.top();
    }

    int getMin() {
        return min.top();
    }
};