class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        char *str = new char[len + 1];
        int t = 0;
        const char* p = s.c_str();
        while (*p != 0) {
            switch(*p) {
                case '(':
                case '[':
                case '{':
                str[t++] = *p;
                break;
                case ')':
                    if (str[--t] != '(') return false;
                break;
                case ']':
                    if (str[--t] != '[') return false;
                break;
                case '}':
                    if (str[--t] != '{') return false;
                break;
            }
            p++;
        }
        return t == 0;
    }
};