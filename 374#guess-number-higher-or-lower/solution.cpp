// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n + 1;
        while(true) {
            int m = l + ((r - l) >> 1);
            int c = guess(m);
            if (c == 0) return m;
            if (c == 1) l = m + 1;
            else r = m;
        }
    }
};