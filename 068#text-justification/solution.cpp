class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if (maxWidth == 0) return words;
        vector<string> ans;
        queue<string> tmp;
        int l = maxWidth, i, t, r;
        for (string& s : words) {
            i = s.length();
            if (!tmp.empty()) i++;
            if (i > l) {
                if (tmp.size() == 1) {
                    ans.push_back(move(tmp.front()));
                    tmp.pop();
                    ans.back().append(l, ' ');
                } else {
                    ans.push_back(move(tmp.front()));
                    tmp.pop();
                    r = l % tmp.size();
                    t = l / tmp.size();
                    while (!tmp.empty()) {
                        if (r > 0) {
                            ans.back().append(t + 2, ' ');
                            r--;
                        } else {
                            ans.back().append(t + 1, ' ');
                        }
                        ans.back().append(tmp.front());
                        tmp.pop();
                    }
                }
                l = maxWidth;
                i = s.length();
            }
            l -= i;
            tmp.push(move(s));
        }
        if (!tmp.empty()) {
            ans.push_back(move(tmp.front()));
            tmp.pop();
            while (!tmp.empty()) {
                ans.back().append(1, ' ');
                ans.back().append(tmp.front());
                tmp.pop();
            }
            ans.back().append(l, ' ');
        }
        return ans;
    }
};
