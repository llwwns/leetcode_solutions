class Solution {
public:
    static short table[128];
    Solution() {
        table['I'] = 1;
        table['V'] = 5;
        table['X'] = 10;
        table['L'] = 50;
        table['C'] = 100;
        table['D'] = 500;
        table['M'] = 1000;
    }
    int romanToInt(string s) {
        int last = 0, current = 0, temp = 0, result = 0;
        for (auto c : s) {
            current = table[c];
            if (current > last) {
                result -= temp;
                temp = current;
                last = current;
            } else if (current == last) {
                temp += current;
            } else {
                result += temp;
                temp = current;
                last = current;
            }
        }
        return result + temp;
    }
};
short Solution::table[128];

