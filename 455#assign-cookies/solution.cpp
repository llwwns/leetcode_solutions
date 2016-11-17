class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0;
        auto p = s.begin();
        for (int x : g) {
            while (p != s.end() && *p < x) {
                p++;
            }
            if (p != s.end()) {
                p++;
                c++;
            } else {
                break;
            }
        }
        return c;
    }
};