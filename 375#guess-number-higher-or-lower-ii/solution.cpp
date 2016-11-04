class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> f(n + 1, vector<int>(n+1, 0));
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= n - i; j++) {
                int m = min(j + f[j + 1][j + i], j + i + f[j][j + i - 1]);
                for (int k = j + 1; k < j + i; k++) {
                    int t = k + max(f[j][k - 1], f[k + 1][j + i]);
                    m = min(m, t);
                }
                f[j][j + i] = m;
            }
        }
        return f[1][n];
    }
};