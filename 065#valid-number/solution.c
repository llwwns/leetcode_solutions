bool isNumber(char* s) {
    bool has_num = false;
    while (*s == ' ') s++;
    if (*s == '-' || *s == '+') s++;
    if (*s <= '9' && *s >= '0') {
        has_num = true;
        do {s++;} while (*s <= '9' && *s >= '0');
    }
    if (*s == '.') {
        s++;
        if (*s <= '9' && *s >= '0') {
            has_num = true;
            do {s++;} while (*s <= '9' && *s >= '0');
        }
    }
    if (!has_num) return false;
    if (*s == 'e') {
        s++;
        if (*s == '-' || *s == '+') s++;
        if (*s > '9' || *s < '0') {
            return false;
        } else {
            do {s++;} while (*s <= '9' && *s >= '0');
        }
    }
    while (*s == ' ') s++;
    return *s == 0;
}
