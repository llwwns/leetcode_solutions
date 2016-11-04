class Solution {
    string parse(string::iterator &p, string::iterator e) {
        string r = "";
        for (; p != e && *p != ']';) {
            if (*p <= '9' && *p >= '0') {
                int k = 0;
                do {
                    k = k * 10 + *(p++) - '0';
                } while (*p <= '9' && *p >= '0');
                string s = parse(++p, e);
                for (;k > 0; k--) r.append(s);
                p++;
            } else {
                r.push_back(*(p++));
            }
        }
        return r;
    }
public:
    string decodeString(string s) {
        string::iterator p = s.begin();
        return parse(p, s.end());
    }
};