class Solution {
public:
    const static char numerals[9];
    const static char table[10][5];
    string intToRoman(int num) {
        string res;
        res.reserve(16);
        const char *pnum;
        const char (*ptable)[5];
        pnum = numerals;
        while (num > 0) {
            ptable = table + num % 10;
            for (const char *p = *ptable; *p >= 0; p++) {
                res.push_back(pnum[*p]);
            }
            num /=10;
            pnum +=2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
const char Solution::numerals[9] = {'I', 'V', 'X', 'L', 'C', 'D', 'M', 'v', 'x'};
const char Solution::table[10][5] = {{-1, -1, -1, -1, -1},
                                    {0, -1, -1, -1, -1},
                                    {0, 0, -1, -1, -1},
                                    {0, 0, 0, -1, -1},
                                    {1, 0, -1, -1, -1},
                                    {1, -1, -1, -1, -1},
                                    {0, 1, -1, -1, -1},
                                    {0, 0, 1, -1, -1},
                                    {0, 0, 0, 1, -1},
                                    {2, 0, -1, -1, -1}};
