class Solution {
public:
    vector<vector<string>> ans;
    vector<int> current;
    string trans(int n, int b) {
        string t;
        t.reserve(n);
        for (int i = 0, j = 1; i < n; i++, j<<=1) {
            if (j == b) t.append("Q");
            else t.append(".");
        }
        return t;
    }
    void nqueen(int n, int d, int col, int lsh, int rsh)
    {
        int bit = (1 << n) - 1;
        if (d >= n)
        {
            vector<string> a;
            a.reserve(n);
            for (auto i:current) {
                a.push_back(trans(n, i));
            }
            ans.push_back(move(a));
        } else {
            int p = col & lsh & rsh & bit;
            while (p > 0) {
                int b = p & ((~p) + 1);
                current[d] = b;
                nqueen(n, d + 1, col ^ b, ((lsh ^ b) << 1) | 1, (rsh ^ b) >> 1);
                p ^= b;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        current.resize(n, 0);
        ans.clear();
        nqueen(n, 0, -1, -1, -1);
        return ans;
    }
};