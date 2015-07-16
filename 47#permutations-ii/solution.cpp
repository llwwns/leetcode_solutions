class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
                for (int j = i + cur[i] + 1; j < n; j++) {
                    if (lst[i + cur[i]] == lst[j]) {
                        goto next;
                    }
                }
                swap(lst[i], lst[i + cur[i]]);
            }
            ans.push_back(lst);
next:
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
