class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        if (num % 390625 == 0) num /= 390625;
        if (num % 625 == 0) num /= 625;
        if (num % 25 == 0) num /= 25;
        if (num % 5 == 0) num /= 5;
        if (num % 43046721 == 0) num /= 43046721;
        if (num % 6561 == 0) num /= 6561;
        if (num % 81 == 0) num /= 81;
        if (num % 9 == 0) num /= 9;
        if (num % 3 == 0) num /= 3;
        if ((num & 0xffff) == 0) num >>= 16;
        if ((num & 0xff) == 0) num >>= 8;
        if ((num & 0xf) == 0) num >>= 4;
        if ((num & 3) == 0) num >>= 2;
        if ((num & 1) == 0) num >>= 1;
        return num == 1;
    }
};
