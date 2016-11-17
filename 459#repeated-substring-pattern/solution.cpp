class Solution {
    bool checkLen(const string& str, int l) {
        int len = str.size();
        for (int j = 0; j < l; j++) {
            char c = str[j];
            for (int k = 1; k * l < len; k++) {
                if (str[k * l + j] != c) {
                    return false;
                } 
            }
        }
        return true;
    }
public:
    bool repeatedSubstringPattern(string str) {
        int len = str.size();
        for (int i = len >> 1; i >= 1; i--) {
            if (len % i == 0 && checkLen(str, i)) {
                cout << i << endl;
                return true;
            }
        }
        return false;
    }
};