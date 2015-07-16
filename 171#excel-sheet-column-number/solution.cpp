class Solution {
public:
    int titleToNumber(string s) {
        int t = 0;
        for (char c:s) {
            t = t * 26 + c - 'A' + 1;
        }
        return t;
    }
};