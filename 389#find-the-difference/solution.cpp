class Solution {
public:
    char findTheDifference(string s, string t) {
        char b = 0;
        for (char c : s) {
            b ^= c;
        }
        for (char c : t) {
            b ^= c;
        }
        return b;
    }
};