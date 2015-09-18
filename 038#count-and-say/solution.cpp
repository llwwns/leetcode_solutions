class Solution {
public:
    string countAndSay(int n) {
        string ret, tmp;
        ret = "1";
        while (n > 1) {
            int c = 1;
            for (auto p = ret.begin() + 1; p != ret.end(); p++) {
                if (*p != *(p-1)) {
                    tmp.push_back('0' + c);
                    tmp.push_back(*(p-1));
                    c = 1;
                } else {
                    c++;
                }
            }
            tmp.push_back('0' + c);
            tmp.push_back(ret.back());
            n--;
            swap (ret, tmp);
            tmp.clear();
        }
        return ret;
    }
};
