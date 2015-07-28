class Solution {
public:
    int findMin(vector<int>& nums) {
        auto p = upper_bound(nums.begin(), nums.end(), nums.front(), greater<int>());
        if (p == nums.end()) return nums.front();
        return *p;
    }
};