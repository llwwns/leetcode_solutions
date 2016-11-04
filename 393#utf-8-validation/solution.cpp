class Solution {
    bool check(vector<int>::iterator &p, vector<int>::iterator end, int n) {
        for (; n > 0; n--, p++) {
            if (p == end || (*p & 0x80) != 0x80 || (*p | 0xbf) != 0xbf) {
                return false;
            } 
        }
        return true;
    }
public:
    bool validUtf8(vector<int>& data) {
        auto p = data.begin();
        for (; p != data.end();) {
            if ((*p | 0x7F) == 0x7f) {
                p++;
                continue;
            }
            if ((*p & 0xc0) == 0xc0 && (*p | 0xdf) == 0xdf) {
                if (!check(++p, data.end(), 1)) {
                    return false;
                }
                continue;
            }
            if ((*p & 0xe0) == 0xe0 && (*p | 0xef) == 0xef) {
                if (!check(++p, data.end(), 2)) {
                    return false;
                }
                continue;
            }
            if ((*p & 0xf0) == 0xf0 && (*p | 0xf7) == 0xf7) {
                if (!check(++p, data.end(), 3)) {
                    return false;
                }
                continue;
            }
            return false;
        }
        return true;
    }
};