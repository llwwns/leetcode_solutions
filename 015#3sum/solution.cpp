class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size(), i, j;
        vector<vector<int>> ans;
        for (i = 0; i < len - 2;) {
            for (j = i + 1; j < len - 1;) {
                if(binary_search(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j])) {
                    ans.push_back(vector<int>{nums[i], nums[j], -nums[i] - nums[j]});
                }
                do {
                    j++;
                } while(j < len - 1 && nums[j] == nums[j-1]);
            }
            do {
                i++;
            } while(i < len - 2 && nums[i] == nums[i-1]);
        }
        return ans;
    }
};