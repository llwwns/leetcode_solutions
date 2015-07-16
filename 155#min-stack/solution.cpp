class MinStack {
    int *arr, *min, len, c;
public:
    MinStack() {
        c = 128;
        len = 1;
        arr = new int[c];
        min = new int[c];
        arr[0] = 0;
        min[0] = 2147483647;
    }
    ~MinStack() {
        delete[] arr;
        delete[] min;
    }
    void push(int x) {
        if (len == c) {
            int *p = new int[c<<1];
            memcpy(p, arr, sizeof(int)*c);
            delete[] arr;
            arr = p;
            p = new int[c<<1];
            memcpy(p, min, sizeof(int)*c);
            delete[] min;
            min = p;
            c <<= 1;
        }
        min[len] = min[len - 1] < x ? min[len - 1] : x;
        arr[len++] = x;
    }

    void pop() {
        len--;
    }

    int top() {
        return arr[len-1];
    }

    int getMin() {
        return min[len-1];
    }
};