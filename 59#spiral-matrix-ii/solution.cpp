class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int s = 1, t = 0, i = 0, j = 0, len = n * n;
        if (n == 1) s++;
        while (t < len) {
            ans[i][j] = ++t;
            switch (s & 3) {
                case 1:
                    if ((++j) + 1 == n - (s >> 2))
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
        }
        return ans;
    }
};