class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int l = digits.size(), t = 1;
        for (int i = 0; i < l; i++) {
            digits[i] = digits[i] + t;
            if (digits[i] < 10) {
                t = 0;
                break;
            }
            t = digits[i] / 10;
            digits[i] %= 10;
        }
        if (t > 0) {
            digits.push_back(t);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};