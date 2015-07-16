void reverse(char* s, char *p) {
    char t;
    --p;
    while (s < p) {
        t = *p;
        *p = *s;
        *s = t;
        ++s;
        --p;
    }
}
void reverseWords(char *s) {
    char *p, *q;
    bool space = true;
    for(p = s, q = s; *p != 0;) {
        if (*p == ' ') {
            if (!space) {
                *(q++) = *(p++);
                space = true;
            } else {
                ++p;
            }
        } else {
            *(q++) = *(p++);
            space = false;
        }
    }
    while (q > s && *(q-1) == ' ') {
        --q;
    }
    *q = 0;
    reverse(s, q);
    for (p = s; *p != 0;) {
        if (*p == ' ') {
            reverse(s, p);
            s = ++p;
        } else{
            ++p;
        }
    }
    reverse(s, p);
}