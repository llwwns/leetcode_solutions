class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool first_row = false;
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        for (auto &l : matrix) {
            if (l[0] == 0) {
                first_row = true;
            }
            for (auto i : l) {
                if (i == 0) {
                    l[0] = 0;
                }
            }
        }
        for (int j = 1; j < m; j++) {
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == 0) {
                    for (int k = 0; k < n; k++) {
                        matrix[k][j] = 0;
                    }
                    break;
                }
            }
        }
        for (auto &l : matrix) {
            if (l[0] == 0) {
                for (int k = 1; k < m; k++) {
                    l[k] = 0;
                }
            }
        }
        if (first_row) {
            for (auto &l : matrix) {
                l[0] = 0;
            }
        }
    }
};