class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }
        vector<int> f(s.size() + 1, 0);
        f[0] = f[1] = 1;
        if (s[0] > '9' || s[0] < '1') return 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0' && s[i - 1] > '2') return 0;
            if (s[i] != '0') f[i + 1] = f[i];
            if (s[i - 1] < '2' && s[i - 1] > '0' || s[i - 1] == '2' && s[i] < '7') {
                f[i + 1] += f[i - 1];
            }
        }
        return f[s.size()];
    }
};