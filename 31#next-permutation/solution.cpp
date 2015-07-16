class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), i, j;
        if (len <= 1) return;
        for (i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (j = len - 1; nums[j] <= nums[i]; j--);
                swap(nums[i], nums[j]);
                break;
            }
        }
        for (i++, j = len - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};
