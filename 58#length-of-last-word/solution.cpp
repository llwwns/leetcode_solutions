class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        bool b = false;
        for (char c : s) {
            if (c == ' ') b = true;
            else {
                if (b) {
                    b = false;
                    l = 0;
                }
                l++;
            }
        }
        return l;
    }
};