class Solution {
    const int MAX_TMP_VALUE = 214748364;
    const int MIN_TMP_VALUE = -214748364;
    const int MAX_TMP_POS = 7;
    const int MAX_TMP_NEG = 8;
public:
    int myAtoi(string str) {
        const char* s = str.c_str();
        for (; *s > 0 && *s == ' '; ++s);
        bool minus = false;
        int tmp = 0, d;
        if (*s == '-') {
            for(++s; *s <= '9' && *s >= '0'; ++s)
            {
                d = *s - '0';
                if (tmp < MIN_TMP_VALUE || tmp == MIN_TMP_VALUE && d > MAX_TMP_NEG) {
                    return -2147483648;
                }
                tmp = tmp * 10 - d;
            }
        } else {
            if (*s == '+') ++s;
            for(; *s <= '9' && *s >= '0'; ++s)
            {
                d = *s - '0';
                if (tmp > MAX_TMP_VALUE || tmp == MAX_TMP_VALUE && d > MAX_TMP_POS) {
                    return 2147483647;
                }
                tmp = tmp * 10 + d;
            }
        }
        return tmp;
    }
};