class Solution {
public:
    static short table[128];
    Solution() {
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
    }
    int romanToInt(string s) {
        const char *p = s.c_str();
        int l = 0, c = 0, t = 0, i = 0;
        while (*p != 0) {
            c = table[*p];
            if (c > l) {
                i -= t;
                t = c;
                l = c;
            } else if (c == l) {
                t += c;
            } else {
                i += t;
                t = c;
                l = c;
            }
            p++;
        }
        return i + t;
    }
};
short Solution::table[128];

