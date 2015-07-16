class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        cur.reserve(k);
        cur.push_back(1);
        while (true) {
            while (cur.size() < k) {
                cur.push_back(cur.back()+1);
            }
            ans.push_back(cur);
            while(true) {
                
                if (cur.back() < n - k + cur.size()) {
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