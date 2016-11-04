class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        int maxLen = 1;
        vector<int> f(len, 1), g(len, 1);
        for (int i = 1; i < len; i++) {
            f[i] = g[i] = 1;
            for (int j = i - 1; j + 2 > f[i] || j + 2 > g[i]; j--) {
                if (nums[i] > nums[j]) {
                    f[i] = max(f[i], 1 + g[j]);
                } else if (nums[i] < nums[j]) {
                    g[i] = max(g[i], 1 + f[j]);
                }
            }
            maxLen = max(maxLen, max(f[i], g[i]));
        }
        return maxLen;
    }
};