class Solution {
public:
    int tnum(const char* &p) {
        int t = 0;
        while (*p <= '9' && *p >= '0') t = t * 10 + *(p++) - '0';
        return t;
    }
    int compareVersion(string version1, string version2) {
        const char *p1 = version1.c_str(), *p2 = version2.c_str();
        int v1, v2;
        while (true) {
            v1 = tnum(p1);
            v2 = tnum(p2);
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
            if (*p1 == '.') p1++;
            if (*p2=='.') p2++;
            if (*p1 == 0 && *p2 == 0) return 0;
        }
    }
};