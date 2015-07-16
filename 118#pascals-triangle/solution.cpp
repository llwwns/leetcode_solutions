class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return vector<vector<int>>();
        vector<vector<int>> ans;
        ans.reserve(numRows);
        ans.push_back(vector<int>{1});
        for (int i = 1; i < numRows; i++) {
            vector<int> r(i + 1);
            int *a = r.data(), *b = ans.back().data();
            a[0] = 1;
            a[i] = 1;
            for (int j = 1; j < i; j++) {
                a[j] = b[j] + b[j-1];
            }
            ans.push_back(move(r));
        }
        return ans;
    }
};