#include <unordered_set>
class Solution {
public:
    int calc(int n) {
        int a = 0;
        while (n > 0) {
            a += (n % 10) * (n % 10);
            n /= 10;
        }
        return a;
    }
    bool isHappy(int n) {
        int k = n;
        while (k != 1) {
            k = calc(calc(k));
            n = calc(n);
            if (k != 1 && n == k) {
                return false;
            }
        }
        return true;
    }
};