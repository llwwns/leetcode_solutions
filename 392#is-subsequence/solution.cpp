class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto ps = s.begin();
        auto pt = t.begin();
        for (;pt != t.end(); pt++) {
            if (*ps == *pt) {
                ps++;
                if (ps == s.end()) {
                    break;
                }
            }
        }
        return ps == s.end();
    }
};