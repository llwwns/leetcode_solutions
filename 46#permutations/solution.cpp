class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size(), i, j;
        if (len == 0) return vector<vector<int>>();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        ans.push_back(nums);
        while (true) {
            for (i = len - 2; i >= 0; i--) {
                if (nums[i] < nums[i + 1]) {
                    for (j = len - 1; nums[j] <= nums[i]; j--);
                    swap(nums[i], nums[j]);
                    break;
                }
            }
            if (i < 0) return ans;
            for (i++, j = len - 1; i < j; i++, j--) {
                swap(nums[i], nums[j]);
            }
            ans.push_back(nums);
        }
    }
};
