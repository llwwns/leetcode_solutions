class Solution {
    int myPow(int x, int n) {
        if (n == 0) {
            return 1;
        }
        int ans = 1, tem = x;
        while (n > 0) {
            if (n & 1) {
                ans = ans * tem % 1337;
            }
            n >>= 1;
            tem = tem * tem % 1337;
        }
        return ans; 
    }
public:
    int superPow(int a, vector<int>& b) {
        int t = a % 1337, y = 1;
        for (auto p = b.rbegin(); p != b.rend(); p++) {
            y = y * myPow(t, *p) % 1337;
            t = myPow(t, 10);
        }
        return y;
    }
};