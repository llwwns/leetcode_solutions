class Solution {
    const static char table[4][5];
    static int countbit(int n) {
        int c = 0;
        while (n > 0) {
            c++;
            n = n ^ (n & -n);
        }
        return c;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ret;
        for (int i = 0; i < 60; i++) {
            int c = countbit(i);
            string s = i < 10 ? "0" + to_string(i) : to_string(i);
            if (c <= num && num - c < 4) {
                for (b : table[num - c]) {
                    if (b < 0) {
                        break;
                    }
                    ret.push_back(to_string(b) + ":" + s);
                }
            }
        }
        return ret;
    }
};

const char Solution::table[4][5] = {
    {0,-1,-1,-1,-1},
    {1, 2, 4, 8,-1},
    {3, 5, 6, 9,10},
    {7,11,-1,-1,-1}
};