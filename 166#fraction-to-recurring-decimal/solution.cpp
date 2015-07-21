class Solution {
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        stringstream s;
        if (numerator / denominator == 0 && (numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)) {
            s << '-';
        }
        s << numerator / denominator;
        numerator %= denominator;
        if (numerator < 0) numerator = -numerator;
        if (denominator < 0) denominator = -denominator;
        long long i = numerator, j = numerator, k = numerator;
        while (true) {
            i = i * 10 % denominator;
            j = j * 10 % denominator;
            j = j * 10 % denominator;
            if (i == j) {
                if (i != k) {
                    s << '.';
                }
                while (i != k) {
                    k *= 10;
                    s << k / denominator;
                    k %= denominator;
                    i = i * 10 % denominator;
                }
                if (i != 0) {
                    if (j == numerator) {
                        s << '.';
                    }
                    s << '(';
                    do {
                        i *= 10;
                        s << i / denominator;
                        i %= denominator;
                    } while (i != k);
                    s << ')';
                }
                return s.str();
            }
        }
    }
};
