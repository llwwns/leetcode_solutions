class MedianFinder {
    priority_queue<int> a;
    priority_queue<int, vector<int>, greater<int>> b;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (a.empty()) {
            a.push(num);
        } else if (num >= a.top()) {
            if (a.size() > b.size()) {
                b.push(num);
            } else {
                b.push(num);
                a.push(b.top());
                b.pop();
            }
        } else {
            if (a.size() > b.size()) {
                a.push(num);
                b.push(a.top());
                a.pop();
            } else {
                a.push(num);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (a.size() > b.size()) {
            return a.top();
        }
        return ((double)a.top() + b.top()) / 2.0;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();