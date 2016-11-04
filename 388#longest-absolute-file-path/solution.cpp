class Solution {
public:
    int lengthLongestPath(string input) {
        int len = 0, i = 0, max = 0, dlen = 0;
        bool is_file = false;
        vector<int> lens;
        for (char c : input) {
            switch (c) {
            case '\n':
                if (len > max && is_file) {
                    max = len;
                }
                if (i >= lens.size()) {
                    lens.push_back(dlen);
                } else {
                    lens[i] = dlen;
                }
                is_file = false;
                dlen = 0;
                len = 0;
                i = 0;
                break;
            case '\t':
                len += lens[i++] + 1;
                break;
            case '.':
                is_file = true;
            default:
                len++;
                dlen++;
                break;
            }
        }
        return len > max && is_file ? len : max;
    }
};