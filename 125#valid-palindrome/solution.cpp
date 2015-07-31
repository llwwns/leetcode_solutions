class Solution {
public:
    bool isPalindrome(string s) {
        auto p = s.begin(), q = s.end() - 1;
        char a, b;
        while (true) {
            for (;p != s.end() && !(*p <= 'Z' && *p >= 'A' || *p <= 'z' && *p >= 'a' || *p >= '0' && *p <= '9'); p++);
            for(;q > p && !(*q <= 'Z' && *q >= 'A' || *q <= 'z' && *q >= 'a' || *q >= '0' && *q <= '9'); q--);
            if (p == s.end() || q <= p) return true;
            a = *p >= 'A' && *p <= 'Z' ? *p - 'A' : *p - 'a';
            b = *q >= 'A' && *q <= 'Z' ? *q - 'A' : *q - 'a';
            if (a != b) return false;
            p++;
            q--;
        }
    }
};