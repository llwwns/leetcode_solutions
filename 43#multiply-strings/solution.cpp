class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> ans(num1.length() + num2.length(), 0);
        for (auto p = num1.rbegin(); p != num1.rend(); p++) {
            for(auto q = num2.rbegin(); q != num2.rend(); q++) {
                ans[(p - num1.rbegin()) + (q - num2.rbegin())] += (*p - '0') * (*q - '0');
            }
        }
        int t = 0;
        for (int& i:ans) {
            t += i;
            i = t % 10;
            t /= 10;
        }
        while (t > 0) {
            ans.push_back(t % 10);
            t /= 10;
        }
        while(ans.back() == 0 && ans.size() > 1) ans.pop_back();
        string s;
        s.reserve(ans.size());
        for (auto p = ans.rbegin(); p != ans.rend(); p++) s.push_back(*p + '0');
        return s;
    }
};
