class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, c = num, i;
        while (c > 0)
        {
            i = l + (c >> 1);
            if (i < num / i) {
                l = i + 1;
                c -= (c >> 1) + 1;
            } else c >>= 1;
        }
        return l * l == num;
    }
};