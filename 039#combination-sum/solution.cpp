class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        vector<int> tmp;
        int len = candidates.size();
        int sum = candidates[0];
        cur.push_back(0);
        while (true) {
            while (sum < target) {
                cur.push_back(cur.back());
                sum += candidates[cur.back()];
            }
            if (sum == target) {
                tmp.clear();
                tmp.reserve(cur.size());
                for(int i:cur) {
                    tmp.push_back(candidates[i]);
                }
                ans.push_back(move(tmp));
            }
            while(true) {
                if (cur.back() + 1 < len && sum - candidates[cur.back()] + candidates[cur.back()+1] <= target) {
                    sum -= candidates[cur.back()++];
                    sum += candidates[cur.back()];
                    break;
                } else {
                    sum -= candidates[cur.back()];
                    cur.pop_back();
                    if (cur.size() == 0) {
                        return ans;
                    }
                }
            }
        }
    }
};
