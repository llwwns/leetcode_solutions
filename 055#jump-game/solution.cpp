class Solution {
public:
    bool canJump(vector<int>& nums) {
        int m = 0;
        for (int i = 0; i <= m && i < nums.size(); i++) {
            m = max(m, i + nums[i]);
        }
        return m >= nums.size() - 1;
    }
};