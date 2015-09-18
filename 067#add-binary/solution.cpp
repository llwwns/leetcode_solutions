class Solution {
public:
    string addBinary(string a, string b) {
        int len = max(a.length(), b.length()) + 2;
        string ans;
        ans.reserve(len);
        int i = a.length() - 1, j = b.length() - 1, t = 0;
        while (i >= 0 && j >= 0) {
            t = a[i] - '0' + b[j] - '0' + t;
            ans.append(1, (t&1) + '0');
            t >>= 1;
            i--;
            j--;
        }
        while (i >= 0) {
            t = a[i] - '0' + t;
            ans.append(1, (t&1) + '0');
            t >>= 1;
            i--;
        }
        while (j >= 0) {
            t = b[j] - '0' + t;
            ans.append(1, (t&1) + '0');
            t >>= 1;
            j--;
        }
        if (t > 0) {
            ans.append(1, t + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
