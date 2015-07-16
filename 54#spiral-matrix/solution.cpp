class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> ans;
        if (n == 0) return ans;
        int m = matrix.front().size();
        if (m == 0) return ans;
        int s = 1, t = 0, i = 0, j = 0, len = n * m;
        ans.reserve(len);
        if (m == 1) s++;
        while (t < len) {
            ans.push_back(matrix[i][j]);
            switch (s & 3) {
                case 1:
                    if ((++j) + 1 == m - (s >> 2))
                        s++;
                    break;
                case 2:
                    if ((++i) + 1 == n - (s >> 2))
                        s++;
                    break;
                case 3:
                    if (--j == (s >> 2))
                        s++;
                    break;
                case 0:
                    if (--i == (s >> 2))
                        s++;
                    break;
            }
            t++;
        }
        return ans;
    }
};