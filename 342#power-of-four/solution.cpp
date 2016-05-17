class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num & (-num)) == num && (num & 0x55555555) != 0;
    }
};