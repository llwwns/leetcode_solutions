class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        if (len == 1) return nums.back();
        if (len == 2) return max(nums[0], nums[1]);
        vector<int> f(len);
        f[0] = 0;
        for (int i = 1; i < len - 1; i++) {
            f[i] = max(f[i - 1], nums[i] + f[i - 2]);
            nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
        }
        return max(nums[len - 2], nums[len - 1] + f[len - 3]);
    }
};