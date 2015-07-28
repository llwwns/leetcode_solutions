class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        auto p = upper_bound(nums.begin(), nums.end(), nums.front(), greater<int>());
        if (p == nums.end()) {
            auto q = lower_bound(nums.begin(), nums.end(), target);
            if (q == nums.end() || *q != target) return -1;
            return q - nums.begin();
        }
        if (target >= nums.front()) {
            auto q = lower_bound(nums.begin(), p, target);
            if (q == p || *q != target) return -1;
            return q - nums.begin();
        }
        auto q = lower_bound(p, nums.end(), target);
        if (q == nums.end() || *q != target) return -1;
        return q - nums.begin();
    }
};
