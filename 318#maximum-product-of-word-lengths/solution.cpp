class Solution {
    pair<int, int> fromWord(const string& s) {
        int r = 0;
        for (char c : s) {
            r |= 1 << (c - 'a');
        }
        return make_pair(r, s.length());
    }
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int, int>> lst;
        lst.reserve(words.size());
        for (string s: words) {
            lst.push_back(fromWord(s));
        }
        int max = 0;
        for (int i = 0; i + 1 < lst.size(); i++) {
            for (int j = i + 1; j < lst.size(); j++) {
                if ((lst[i].first & lst[j].first) == 0 && lst[i].second * lst[j].second > max) {
                    max = lst[i].second * lst[j].second;
                }
            }
        }
        return max;
    }
};