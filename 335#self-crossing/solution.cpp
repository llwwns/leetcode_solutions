class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int a, b, c, d, i, len = x.size();
        if (x.size() <= 3) {
            return false;
        }
        for (d = 0, c = 0, b = x[0], a = x[1], i = 2; i < len; d = c, c = b, b = a, a = x[i++]) {
            if (x[i] <= b && x[i] >= b - d) {
                b = a - c;
                a = x[i++];
                break;
            } else if(x[i] < b - d) {
                b = a;
                a = x[i++];
                break;
            }
        }
        for (; i < len; b = a, a = x[i++]) {
            if (x[i] >= b) {
                return true;
            }
        }
        return false;
    }
};