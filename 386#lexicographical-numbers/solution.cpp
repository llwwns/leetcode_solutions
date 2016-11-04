class Solution {
    vector<int> r;
    void calc(int c, int n) {
        if (c > 0 && c <= n) {
            r.push_back(c);
            for (int i = 0; i < 10; i++) {
                calc(c * 10 + i, n);
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        r.clear();
        for (int i = 1; i < 10; i++) {
            calc(i, n);
        }
        return r;
    }
};