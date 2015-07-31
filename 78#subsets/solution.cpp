class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> lst;
        sort(nums.begin(), nums.end());
        long set = (1 << (long)nums.size()) - 1;
        vector<vector<int>> res(set);
        while (set >= 0) {
            lst.clear();
            for (long i = 0; i < nums.size(); i++) {
                if ((1 << i) & set) {
                    lst.push_back(nums[i]);
                }
            }
            ans.push_back(move(lst));
            set--;
        }
        return ans;
    }
};