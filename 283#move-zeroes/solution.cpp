class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto p = nums.begin();
        auto q = nums.begin();
        auto e = nums.end();
        for (;p != e; p++) {
            if (*p  != 0) {
                *(q++) = *p;
            }
        }
        while (q != p) {
            *(q++) = 0;
        }
    }
};