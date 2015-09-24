class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i, j = 0, len = nums.size();
        for (i = 0; i < len; i++) {
            if (nums[i] != 0) nums[j++] = nums[i];
        }
        while (j < i) {
            nums[j++] = 0;
        }
    }
};