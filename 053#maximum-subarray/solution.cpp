class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int sum = 0, max = nums[0];
        for (int i : nums) {
            if (sum > 0) {
                sum += i;
            } else {
                sum = i;
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};