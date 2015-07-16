class Solution {
public:
    int countDigitOne(int n) {
        int b, c = 0, m = 0, k = 1;
        while (n > 0) {
            b = n % 10;
            n /= 10;
            c += n * k;
            if (b > 1) {
                c += k;
            } else if (b == 1) {
                c += m + 1;
            }
            m += k * b;
            k *= 10;
        }
        return c;
    }
};