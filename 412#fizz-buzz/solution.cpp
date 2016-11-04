class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret;
        for (int i = 1; i <= n; i++) {
            string s;
            if (i % 3 == 0) {
                s = "Fizz";
            }
            if (i % 5 == 0) {
                s += "Buzz";
            }
            if (i % 3 != 0 && i % 5 != 0) {
                s = to_string(i);
            }
            ret.push_back(s);
        }
        return ret;
    }
};