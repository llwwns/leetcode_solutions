class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), m, a;
        while (l < r) {
            m = (l >> 1) + (r >> 1) + (l&r&1);
            if (nums[m] >= target) r = m;
            else l = m + 1;
        };
        if (l >= nums.size() || nums[l] > target) return vector<int>{-1, -1};
        a = l; r = nums.size();
        while (l < r) {
            m = (l >> 1) + (r >> 1) + (l&r&1);
            if (nums[m] > target) r = m;
            else l = m + 1;
        };
        return vector<int>{a, l - 1};
    }
};