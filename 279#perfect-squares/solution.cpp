class Solution {
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        int *f = new int[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = f[i-1] + 1;
            for(int j = 2; j * j <= i; j++) {
                f[i] = min(f[i], f[i - j * j] + 1);
            }
        }
        return f[n];
    }
};