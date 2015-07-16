class Solution {
    int total;
    void nqueen(int n, int d, int col, int lsh, int rsh)
    {
        int bit = (1 << n) - 1;
        if (d >= n)
        {
            total ++;
        } else {
            int p = col & lsh & rsh & bit;
            while (p > 0) {
                int b = p & ((~p) + 1);
                nqueen(n, d + 1, col ^ b, ((lsh ^ b) << 1) | 1, (rsh ^ b) >> 1);
                p ^= b;
            }
        }
    }
public:
    int totalNQueens(int n) {
        if (n == 1) {
             return 1;
        }
        total = 0;
        nqueen(n, 0, -1, -1, -1);
        return total;
    }
};