int lengthOfLongestSubstring(char* s) {
    char* p[255];
    char *q = s;
    char *t;
    memset(p, 0, sizeof(p));
    int len = 0, max = 0;
    while (*s != 0) {
        if (!p[*s]) {
            ++len;
        } else {
            if (len > max) {
                max = len;
            }
            t = p[*s];
            while (q != t) {
                p[*(q++)] = 0;
            };
            p[*(q++)] = 0;
            len = s - q + 1;
        }
        p[*s] = s;
        ++s;
    }
    return max > len ? max : len;
}