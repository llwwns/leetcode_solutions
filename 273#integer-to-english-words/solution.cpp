class Solution {
    const static char nums[20][11];
    const static char nums2[8][9];
    const static char nums3[2][9];
    const static char nums4[3][10];
public:
    void addInThousand(string &s, int n) {
        if (n >= 100) {
            s.append(nums[n / 100]);
            s.append(nums3[1]);
            n %= 100;
        }
        if (n >= 20) {
            s.append(nums2[n / 10 - 2]);
            n %= 10;
        }
        if (n != 0) {
            s.append(nums[n]);
        }
    }
    string numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        string ret;
        int i = 2, j = 1000000000;
        do {
            if (num >= j) {
                addInThousand(ret, num / j);
                ret.append(nums4[i]);
                num %= j;
            }
            j /= 1000;
            i--;
        } while (i >= 0);
        addInThousand(ret, num);
        ret.pop_back();
        return ret;
    }
};
const char Solution::nums[20][11] = {
    "Zero ",
    "One ",
    "Two ",
    "Three ",
    "Four ",
    "Five ",
    "Six ",
    "Seven ",
    "Eight ",
    "Nine ",
    "Ten ",
    "Eleven ",
    "Twelve ",
    "Thirteen ",
    "Fourteen ",
    "Fifteen ",
    "Sixteen ",
    "Seventeen ",
    "Eighteen ",
    "Nineteen ",
};
const char Solution::nums2[8][9] = {
    "Twenty ",
    "Thirty ",
    "Forty ",
    "Fifty ",
    "Sixty ",
    "Seventy ",
    "Eighty ",
    "Ninety "
};
const char Solution::nums3[2][9] = {
    "Ten ",
    "Hundred "
};
const char Solution::nums4[3][10] = {
    "Thousand ",
    "Million ",
    "Billion "
};
