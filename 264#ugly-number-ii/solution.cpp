class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> lst;
        lst.reserve(n);
        lst.push_back(1);
        auto p2 = lst.begin();
        auto p3 = lst.begin();
        auto p5 = lst.begin();
        for (int i = 2; i <= n; i++) {
            long m = min(min(*p2 * 2, *p3 * 3), *p5 * 5);
            lst.push_back(m);
            if (m == *p2 * 2) {
                p2++;
            }
            if (m == *p3 * 3) {
                p3++;
            }
            if (m == *p5 * 5) {
                p5++;
            }
        }
        return lst.back();
    }
};