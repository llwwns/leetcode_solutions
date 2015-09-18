bool isMatch(char* s, char* p) {
    while (*s != 0 && *p != 0 && *(p+1) != '*') {
        if (*p != '.' && *s != *p) {
            return false;
        }
        s++;
        p++;
    }
    if (*s == 0 && *p == 0) return true;
    if (*p == 0) return false;
    if (*s == 0 && *(p+1) != '*') return false;
    if (isMatch(s, p + 2)) {
            return true;
    }
    while(*s != 0) {
        if (*p != '.' && *s != *p) {
            return false;
        }
        if (isMatch(s + 1, p + 2)) {
            return true;
        }
        s++;
    }
    return false;
}
