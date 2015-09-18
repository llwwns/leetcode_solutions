class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) return string();
        int len = s.size(), len2 = 0;
        const char * str = s.data();
        int* map = new int[128];
        int* count = new int[128];
        int total = 0;
        memset(map, 0, sizeof(int)*128);
        memset(count, 0, sizeof(int)*128);
        for (char c : t) {
            if (map[c]++ == 0) {
                len2++;
            }
        }
        int i = 1, j = 0, m = len, mi = 0;
        if (map[*str]) {
            count[*str]++;
            if (count[*str] == map[*str]) {
                total++;
            }
        }
        while (i <= len) {
            if (total < len2) {
                char c = str[i++];
                if (map[c]) {
                    if (++count[c] == map[c]) {
                        total++;
                    }
                }
            } else if ((map[str[j]] == 0 || count[str[j]] > map[str[j]]) && j + 1 < i) {
                char c = str[j++];
                if (map[c]) count[c]--;
            } else {
                if (i - j < m) {
                    mi = j;
                    m = i - j;
                }
                char c = str[i++];
                if (map[c]) {
                    if (++count[c] >= map[c]) {
                        total++;
                    }
                }
            }
        }
        if (i > len && j == 0 && total < len2) return string();
        return s.substr(mi, m);
    }
};