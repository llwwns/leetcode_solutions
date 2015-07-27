class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> f(m, 1);
        f[0] = grid[0][0];
        for (int j = 1; j < m; j++) {
            f[j] = grid[0][j] + f[j-1];
        }
        for (int i = 1; i < n; i++) {
            f[0] += grid[i][0];
            for(int j = 1; j < m; j++) {
                f[j] = grid[i][j] + min(f[j], f[j-1]);
            }
        }
        return f[m-1];
    }
};