class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return vector<int>();
        if (len == 1) return vector<int>{1};
        vector<int> out(nums);
        for (int i = 1; i < len; i++) {
            nums[i] *= nums[i-1];
            out[len - i - 1] *= out[len - i];
        }
        out[0] = out[1];
        for (int i = 1; i < len-1; i++) {
            out[i] = out[i+1] * nums[i - 1];
        }
        out[len - 1] = nums[len - 2];
        return out;
    }
};