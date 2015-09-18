class Solution {
public:
    string simplifyPath(string path) {
        string ret;
        path.push_back('/');
        ret.reserve(path.length());
        stack<int, vector<int>> s;
        int dc = 0;
        bool empty = false;
        for (char c : path) {
            if (c == '/') {
                if (empty && dc <= 1) {
                    ret.resize(s.top());
                } else if (empty && dc == 2) {
                    if (s.top() > 1) {
                        s.pop();
                    } 
                    ret.resize(s.top());
                } else {
                    ret.push_back(c);
                    s.push(ret.size());
                }
                dc = 0;
                empty = true;
            } else if (c == '.') {
                ret.push_back(c);
                dc++;
            } else {
                empty = false;
                ret.push_back(c);
            }
        }
        if (ret.length() > 1) ret.pop_back();
        return ret;
    }
};
