class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        vector<int> lens;
        for (int num : nums) {
            auto p = lower_bound(lens.begin(), lens.end(), num);
            if (p == lens.end()) {
                lens.push_back(num);
            } else {
                *p = num;
            }
        }
        return lens.size();
    }
};