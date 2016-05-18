class Solution {

public:
    bool isValidSerialization(string preorder) {
        bool val;
        int tc = 1;
        vector<bool> lst;
        for (auto c: preorder) {
            switch (c) {
            case ',':
                if (val) {
                    if ((--tc) <= 0) {
                        return false;
                    }
                } else {
                    tc++;
                }
                break;
            case '#':
                val = true;
                break;
            default:
                val = false;
                break;
            }
        }
        return tc == 1 && val;
    }
};