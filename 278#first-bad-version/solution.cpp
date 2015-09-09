// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int s, l = 1;
        while (n > 0) {
            s = n >> 1;
            if (!isBadVersion(l + s)) {
                l += s + 1;
                n -= s + 1;
            } else {
                n = s;
            }
        }
        return l;
    }
};