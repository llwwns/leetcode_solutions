class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            sum.resize(0);
            return;
        }
        sum.resize(matrix.size());
        sum[0].resize(matrix[0].size());
        sum[0][0] = matrix[0][0];
        for (int j = 1; j < matrix[0].size(); j++) {
            sum[0][j] = matrix[0][j] + sum[0][j - 1];
        }
        for (int i = 1; i < matrix.size(); i++) {
            sum[i].resize(matrix[i].size());
            sum[i][0] = matrix[i][0] + sum[i - 1][0];
            for (int j = 1; j < matrix[i].size(); j++) {
                sum[i][j] = matrix[i][j] + sum[i][j - 1] + sum[i-1][j] - sum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sum.size() == 0) {
            return 0;
        }
        int s = sum[row2][col2];
        if (row1 > 0) s -= sum[row1 - 1][col2];
        if (col1 > 0) s -= sum[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) s += sum[row1 - 1][col1 - 1];
        return s;
    }
};



// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);