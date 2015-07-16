class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n&1) return n == 1;
        n >>= 1;
        return n != 0 && n == (n & (-n));
    }
};