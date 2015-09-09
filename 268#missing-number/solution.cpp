class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        int u = nums.front();
        int d = nums.front();
        int t = 0;
        for (int i : nums) {
            t ^= i;
            if (i > u) u = i;
            else if (i < d) d = i;
        }
        for (int i = 1; i <= u; i++) t ^= i;
        if (t != 0) return t;
        return d == 0 ? u +  1 : 0;
    }
};