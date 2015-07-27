class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        auto p = s.begin();
        auto q = t.begin();
        array<char, 128> map1{{0}}, map2{{0}};
        for (; p != s.end(); p++,q++) {
            if (map1[*p] != 0 && map1[*p] != *q) return false;
            if (map2[*q] != 0 && map2[*q] != *p) return false;
            map1[*p] = *q;
            map2[*q] = *p;
        }
        return true;
    }
};