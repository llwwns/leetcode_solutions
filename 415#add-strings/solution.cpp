class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        ret.reserve(max(num1.size(), num2.size()));
        auto p = num1.rbegin(), q = num2.rbegin();
        int t = 0;
        for (;p != num1.rend() && q != num2.rend(); p++, q++) {
            t += *p - '0' + *q - '0';
            ret.push_back(t % 10 + '0');
            t /= 10;
        }
        for (; p != num1.rend(); p++) {
            t += *p - '0';
            ret.push_back(t % 10 + '0');
            t /= 10;
        }
        for (; q != num2.rend(); q++) {
            t += *q - '0';
            ret.push_back(t % 10 + '0');
            t /= 10;
        }
        if (t > 0) {
            ret.push_back(t + '0');
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};