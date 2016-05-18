class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) {
            return s;
        }
        auto c = s.begin();
        auto rc = s.rbegin();
        while (c != rc.base()) {
            swap(*c, *rc);
            if (++c == (rc++).base()) {
                break;
            }
        }
        return s;
    }
};