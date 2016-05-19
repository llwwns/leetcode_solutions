class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto p = prices.begin();
        auto e = prices.end();
        if (p == e) {
            return 0;
        }
        int minl = *(p++), maxv = 0;
        for (;p != e; p++) {
            if (*p - minl > maxv) {
                maxv = *p - minl;
            }
            if (*p < minl) {
                minl = *p;
            }
        }
        return maxv;
    }
};