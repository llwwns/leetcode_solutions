class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min = *min_element(nums.begin(), nums.end());
        int t = 0;
        for (int n : nums) {
            t += n - min;
        }
        return t;
    }
};