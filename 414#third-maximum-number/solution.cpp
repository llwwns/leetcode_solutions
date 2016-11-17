class Solution {
public:
    int thirdMax(vector<int>& nums) {
        array<int, 3> maxs;
        maxs[0] = *max_element(nums.begin(), nums.end());
        bool has_max;
        for (int i = 1; i < 3; i++) {
            has_max = false;
            for (int j : nums) {
                if (j < maxs[i - 1] && (!has_max || j > maxs[i])) {
                    maxs[i] = j;
                    has_max = true;
                }
            }
            if (!has_max) {
                return maxs[0];
            }
        }
        return maxs[2];
    }
};