int getnum(char **s) {
    int n = 0;
    while (**s <= '9' && **s >='0') {
        n = n * 10 + (**s - '0');
        (*s)++;
    }
    (*s)--;
    return n;
}
int calc(char **s) {
    int res = 0;
    bool min = false;
    while (**s != 0 && **s != ')') {
        if (**s == '-') {
            min = true;
        } else if (**s == '+') {
            min = false;
        } else if (**s == '(') {
            (*s)++;
            int r = calc(s);
            if (min) {
                res -= r;
            } else {
                res += r;
            }
        } else if (**s >= '0' && **s <= '9') {
            int r = getnum(s);
            if (min) {
                res -= r;
            } else {
                res += r;
            }
        }
        (*s)++;
    }
    return res;
}
int calculate(char* s) {
    return calc(&s);
}