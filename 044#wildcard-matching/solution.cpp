class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size(), l2 = p.size();
        vector<vector<bool>> match(l1 + 1, vector<bool>(l2 + 1, false));
        match[0][0] = true;
        for (int j = 1; j <= l2; j++) {
            if (p[j - 1] == '*') {
                match[0][j] = match[0][j - 1];
                for (int i = 1; i <= l1; i++) {
                    match[i][j] = match[i][j - 1] || match[i - 1][j];
                }
            } else {
                for (int i = 1; i <= l1; i++) {
                    if (p[j - 1] == '?' || p[j - 1] == s[i - 1]) {
                        match[i][j] = match[i - 1][j - 1];
                    }
                }
            }
        }
        return match[l1][l2];
    }
};
