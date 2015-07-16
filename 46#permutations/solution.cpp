class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur,lst;
        int n = nums.size();
        cur.reserve(n);
        lst.resize(n);
        cur.push_back(0);
        while (true) {
            while (cur.size() < n - 1) {
                cur.push_back(0);
            }
            lst = nums;
            for (int i = 0; i < n - 1; i++) {
                swap(lst[i], lst[i + cur[i]]);
            }
            ans.push_back(lst);
            while(true) {
                if (cur.back() < n - (int)cur.size()) {
                    cur.back()++;
                    break;
                } else {
                    cur.pop_back();
                    if (cur.size() == 0) {
                        return ans;
                    }
                }
            }
        }
    }
};
