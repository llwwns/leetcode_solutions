class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len <= 1 || numRows <= 1) return s;
        string ret(len, 0);
        int i, j, k, t = 0;
        numRows--;
        int drow = numRows << 1;
        int col = len / drow;
        for (j = 0; j * drow < len; j++) {
            ret[j] = s[j * drow];
        }
        t = j;
        for (i = 1; i < numRows; i++) {
            for (j = 0; j * drow + i < len; j++) {
                ret[(j << 1) + t] = s[j * drow + i];
            }
            for (k = 0; k * drow + drow - i < len; k++) {
                ret[(k << 1) + t + 1] = s[k * drow + drow - i];
            }
            t += max((j << 1) - 1, (k << 1));
        }
        for (k = 0; k * drow + numRows < len; k++) {
            ret[k + t] = s[k * drow + numRows];
        }
        return ret;
    }
};
