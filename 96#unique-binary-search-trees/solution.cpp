class Solution {
public:
    int numTrees(int n) {
        int *a = new int[n + 1];
        int b;
        a[0] = 1;
        for (int i = 1; i <= n; i++) {
            a[i] = 0;
            for (int j = 1;  j <= i; j++) {
                a[i] += a[j - 1] * a[i - j];
            }
        }
        b = a[n];
        delete [] a;
        return b;
    }
};