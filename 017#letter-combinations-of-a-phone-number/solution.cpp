class Solution {
    const static char * const letter_map[10];
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.length() == 0) return ans;
        for (char& c:digits) {
            c -= '0';
        }
        string cur;
        vector<const char*> tmp;
        int len = digits.length();
        tmp.reserve(len);
        while (true) {
            while (tmp.size() < len) {
                tmp.push_back(letter_map[digits[tmp.size()]]);
            }
            cur.clear();
            cur.reserve(len);
            for (auto p : tmp) {
                cur.push_back(*p);
            }
            ans.push_back(move(cur));
            while(true) {
                if (*(++tmp.back()) != 0) {
                    break;
                } else {
                    tmp.pop_back();
                    if (tmp.size() == 0) {
                        return ans;
                    }
                }
            }
        }
    }
};
const char* const Solution::letter_map[10] = {
    " ",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};
