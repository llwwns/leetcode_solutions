class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int l = 0, r = 0, i = 0;
        char *s = new char[n * 2 + 1];
        char *b = s;
        b[n*2] = 0;
        vector<string> ans;
        while (true) {
            while (l < n) {
                *(b++) = '(';
                l++;
            }
            while (true) {
                if (r < l) {
                   *(b++) = ')';
                    r++;
                    break;
                } else {
                    if (r == n) {
                        ans.emplace_back(s);
                    }
                    while (true) {
                        if (b-- == s) return ans;
                        if (*b == '(') {
                            l--;
                            break;
                        } else {
                            r--;
                        }
                    }
                }
            }
        }
    }
};