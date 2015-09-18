class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<int> f(m, 1);
        f[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int j = 1; j < m; j++) {
            f[j] = obstacleGrid[0][j] == 1 ? 0 : f[j - 1];
        }
        for (int i = 1; i < n; i++) {
            f[0] = obstacleGrid[i][0] == 1 ? 0 : f[0];
            for(int j = 1; j < m; j++) {
                f[j] = obstacleGrid[i][j] == 1 ? 0 : f[j-1] + f[j];
            }
        }
        return f[m-1];
    }
};