class Solution {
public:
    const static int fact[13];
    string getPermutation(int n, int k) {
        string s(n, '0');
        bool st[10]{};
        int c = n, i, j;
        k--;
        while (c > 1) {
            int t = k / fact[c - 1];
            k %= fact[c - 1];
            for (i = 1, j = 0; j <= t;i++) {
                if (!st[i]) j++;
            }
            i--;
            st[i] = true;
            s[n-c] += i;
            c--;
        }
        for (i = 1; st[i]; i++);
        s[n-1] += i;
        return s;
    }
};
const int Solution::fact[13] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880,3628800,39916800,479001600};
