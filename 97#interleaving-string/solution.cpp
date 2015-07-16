class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.length();
        int l2 = s2.length();
        if (s3.length() != l1 + l2) return false;
        if (l1 < l2) {
            swap(l1, l2);
            swap(s1, s2);
        }
        bool *f = new bool[l2 + 1];
        int i, j, l = l2 + 1;
        f[0] = true;
        for (j = 1; j <= l2; j++)
            f[j] = f[j - 1] && s2[j - 1] == s3[j - 1]; 
        for (i = 1; i <= l1; i++) {
            f[0] = f[0] && s1[i - 1] == s3[i - 1];
            for (j = 1; j <= l2; j++) {
                f[j] = f[j] && s1[i - 1] == s3[i + j - 1] || f[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        bool r = f[l2];
        delete[] f;
        return r;
    }
};
