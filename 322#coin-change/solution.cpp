class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, -1);
        f[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (auto c : coins) {
                if (i >= c && f[i - c] >= 0) {
                    int v = f[i - c] + 1;
                    if (f[i] == -1 || v < f[i]) {
                        f[i] = v;
                    }
                }
            }
        }
        return f[amount];
    }
};