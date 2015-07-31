class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        int len = nums.size();
        for (int i = 1; i < len; i++) {
            nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
        }
        return nums.back();
    }
};