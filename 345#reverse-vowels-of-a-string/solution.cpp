class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        if (s.empty()) {
            return s;
        }
        auto c = s.begin();
        auto rc = s.rbegin();
        
        while(c != rc.base()) {
            while (!isVowel(*c) && c != rc.base()) {
                c++;
            }
            while (!isVowel(*rc) && c != rc.base()) {
                rc++;
            }
            if (c != rc.base()) {
                swap(*c, *rc);
                if (++c == (rc++).base()) {
                    break;
                }
            }
        }
        return s;
    }
};