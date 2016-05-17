class Solution {
public:
    int pow (int a, int b) {
        int r = 1;
        while (b > 0) {
            if (b & 1) {
                r *= a;
            }
            a *= a;
            b >>= 1;
        }
        return r;
    }
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        switch (n % 3) {
        case 0:
            return pow(3, n / 3);
        case 1:
            return pow(3, n / 3 - 1) * 4;
        default:
            return pow(3, n / 3) * 2;
        }
    }
};