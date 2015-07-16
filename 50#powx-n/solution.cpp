class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        int t = n < 0 ? -n : n;
        double ans = 1, tem = x;
        while (t > 0) {
            if (t & 1) {
                ans *= tem;
            }
            t >>= 1;
            tem *= tem;
        }
        return n < 0 ? 1 / ans : ans; 
    }
};