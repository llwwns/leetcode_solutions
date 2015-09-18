int strStr(char* haystack, char* needle) {
    int l1 = strlen(haystack);
    int l2 = strlen(needle);
    if (l2 > l1) return -1;
    if (l2 == 0) return 0;
    if (l2 == 1) {
        char *p = strchr(haystack, *needle);
        return  p == NULL ? -1 : p - haystack;
    }
    int *t = malloc(sizeof(int) *l2);
    t[0] = -1;
    t[1] = 0;
    int i = 2, j = 0;
    while (i < l2) {
        if (needle[i - 1] == needle[j]) {
            t[i] = j + 1;
            i++;
            j++;
        } else if (j > 0) {
            j = t[j];
        } else {
            t[i] = 0;
            i++;
        }
    }
    i = 0, j = 0;
    while (i + j < l1) {
        if (needle[j] == haystack[i + j]) {
            j++;
            if (j == l2){
                free(t);
                return i;
            }
        } else {
            i = i + j - t[j];
            if (j > 0) j = t[j];
        }
    }
    free(t);
    return -1;
}