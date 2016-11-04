class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0, t;
        for (int n : nums) {
            t = (b & n) | (a & ~n);
            b = (n & ~(a | b)) | (b & ~n);
            a = t;
        }
        return b;
    }
};