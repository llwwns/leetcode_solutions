class Solution {
public:
    string convertToTitle(int n) {
        char stack[255];
        char *ptr = stack + 254;
        *ptr = 0;
        while (n > 0) {
            *(--ptr) = 'A' + (n - 1) % 26;
            n = (n - 1) / 26;
        }
        return string(ptr);
    }
};