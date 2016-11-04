class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty()) {
            return nums;
        }
        sort(nums.begin(), nums.end());
        vector<int> f(nums.size(), 1);
        vector<int> g(nums.size(), -1);
        int maxi = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    int r = f[j] + 1;
                    if (r > f[i]) {
                        f[i] = r;
                        g[i] = j;
                    }
                }
            }
            if (f[i] > f[maxi]) {
                maxi = i;
            }
        }
        vector<int> res;
        for (int i = maxi; i >= 0; i = g[i]) {
            res.push_back(nums[i]);
        }
        return res;
    }
};