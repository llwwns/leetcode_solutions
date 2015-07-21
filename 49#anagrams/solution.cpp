class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<pair<string, string>> lst;
        lst.reserve(strs.size());
        for (auto &str:strs) {
            auto s2 = str;
            sort(s2.begin(), s2.end());
            lst.push_back(make_pair(move(s2), move(str)));
        }
        sort(lst.begin(), lst.end(), [](const pair<string, string> &a, const pair<string, string> &b){
            return a.first < b.first;
        });
        strs.clear();
        bool a = false;
        auto p = lst.begin();
        for (; p + 1 != lst.end(); p++) {
            if ((*p).first == (*(p+1)).first) {
                a = true;
                strs.push_back(move((*p).second));
            } else {
                if (a) strs.push_back(move((*p).second));
                a = false;
            }
        }
        if (a) strs.push_back(move((*p).second));
        return strs;
    }
};