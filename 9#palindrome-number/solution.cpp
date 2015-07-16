class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int b = x, c = 1;
        while (b >= 10) c *= 10, b /= 10;
        while (x > 0) {
            if (x / c != x % 10) return false;
            x %= c;
            x /= 10;
            c /= 100;
        }
        return true;
    }
};