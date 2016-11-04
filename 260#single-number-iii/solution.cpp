class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for (int n : nums) {
            x ^= n;
        }
        int b = x & (-x);
        vector<int> r(2);
        for (int n : nums) {
            if (n & b) {
                r[0] ^= n;
            } else {
                r[1] ^= n;
            }
        }
        return r;
    }
};