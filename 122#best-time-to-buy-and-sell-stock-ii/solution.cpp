class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) {
            return 0;
        }
        auto p = prices.begin();
        auto q = p++;
        auto e = prices.end();
        int minl = *q, val = 0;
        for (;p != e; p++, q++) {
            if (*p < *q) {
                if (*q > minl) {
                    val += *q - minl;
                }
                minl = *p;
            }
        }
        if (*q > minl) {
            val += *q - minl;
        }
        return val;
    }
};