class Solution {
public:
    const static int max_length = 16;
    const static char numerals[9];
    const static char table[10][5];
    string intToRoman(int num) {
        char result[max_length + 1];
        char *res = result + max_length;
        *(res--) = 0;
        const char *pnum;
        const char (*ptable)[5];
        pnum = numerals;
        while (num > 0) {
            ptable = table + num % 10;
            for (const char *p = *ptable; *p >= 0; p++) {
                *(res--) = pnum[*p];
            }
            num /=10;
            pnum +=2;
        }
        return string(res + 1);
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
