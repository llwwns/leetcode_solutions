class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto itr = strs.begin();
        if (itr == strs.end()) {
            return string("");
        }
        int len = (*itr).length();
        const char *first = (*itr).c_str();
        ++itr;
        for(; itr != strs.end() && len > 0; ++itr) {
            const char *s = (*itr).c_str();
            for (int i = 0; i < len; i++)
                if (s[i] != first[i]) {
                    len = i;
                    break;
                }
        }
        return strs.front().substr(0, len);
    }
};