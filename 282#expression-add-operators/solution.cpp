class Solution {
    vector<string> ans;
    string tmp;
    int target;
public:
    void calc(const char *s, long long k, long long b) {
        long long t = 0;
        int l = tmp.size();
        for (;; s++) {
            if (t == 0 && !tmp.empty() && tmp.back() == '0') {
                tmp.resize(l);
                return;
            }
            t = t * 10 + *s - '0';
            tmp.push_back(*s);
            if (*(s+1) == 0) {
                if (t * k + b == target) {
                    ans.push_back(tmp);
                }
                tmp.resize(l);
                return;
            }
            tmp.push_back('+');
            calc(s+1, 1, t * k + b);
            tmp.back() = '-';
            calc(s+1, -1, t * k + b);
            tmp.back() = '*';
            calc(s+1, t * k, b);
            tmp.pop_back();
        }
        tmp.resize(l);
    }
    vector<string> addOperators(string num, int target) {
        tmp.clear();
        ans.clear();
        Solution::target = target;
        calc(num.c_str(), 1, 0);
        return ans;
    }
};