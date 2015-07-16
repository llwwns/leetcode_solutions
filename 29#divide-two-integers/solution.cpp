class Solution {
public:
    int log(unsigned long long n) {
        const static unsigned long long b[] = {0x2ull, 0xCull, 0xF0ull, 0xFF00ull, 0xFFFF0000ull, 0xFFFFFFFF00000000ull};
        const static unsigned int S[] = {1, 2, 4, 8, 16, 32};
        int i;
        unsigned int r = 0;
        for (i = 5; i >= 0; i--)
        {
            if (n & b[i])
            {
                n >>= S[i];
                r |= S[i];
            } 
        }
        return r;
    }
    int divide(long long dividend, long long divisor) {
        bool m = false;
        if (dividend == -2147483648 && divisor == -1) return 2147483647;
        if (dividend < 0) {dividend = -dividend;m = !m;}
        if (divisor < 0) {divisor = -divisor;m = !m;}
        int b = log(dividend), d = 0;
        while (b >= 0) {
            if (dividend >= (divisor << b)) {
                d |= 1 << b;
                dividend -= (divisor << b);
            }
            b--;
        }
        return m?-d:d;
    }
};
