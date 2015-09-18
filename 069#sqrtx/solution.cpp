class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        int l = 1, r = x, m;
        while(l < r - 1) {
            m = (l + r) >> 1;
            if (m < x / m) {
                l = m;
            } else if (m > x / m) {
                r = m;
            } else {
                return m;
            }
        }
        return l;
    }
};