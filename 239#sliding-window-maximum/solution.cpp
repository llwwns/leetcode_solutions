class Solution {
    int *a, *h;
    vector<int> heap;
    vector<int> index;
    void fixUp(int i, int l) {
        int j = i >> 1;
        while (j > 0) {
            if (a[h[j]] < a[h[i]]) {
                swap(h[j], h[i]);
                swap(index[h[j]], index[h[i]]);
            } else {
                return;
            }
            i >>= 1;
            j = i >> 1;
        }
    }
    void fixDown(int i, int l) {
        int j = i << 1;
        while (j <= l) {
            if (j < l && a[h[j]] < a[h[j+1]]) j++;
            if (a[h[j]] > a[h[i]]) {
                swap(h[j], h[i]);
                swap(index[h[j]], index[h[i]]);
            } else {
                return;
            }
            i = j;
            j = i << 1;
        }
    }
    void makeHeap(int l) {
        for (int i = l >> 1; i > 0; i--) {
            fixDown(i, l);
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k < 2) return nums;
        a = nums.data();
        int len = nums.size();
        heap.resize(k);
        index.resize(len);
        h = heap.data();
        for (int i = 0; i < k; i++) {
            h[i] = i;
            index[i] = i + 1;
        }
        h--;
        makeHeap(k);
        vector<int> ret;
        ret.reserve(len - k + 1);
        ret.push_back(a[h[1]]);
        int j;
        for (int i = k; i < len; i++) {
            j = index[i] = index[i - k];
            h[j] = i;
            fixUp(j, k);
            fixDown(j, k);
            ret.push_back(a[h[1]]);
        }
        return ret;
    }
};
