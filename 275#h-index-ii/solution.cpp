class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i = 0, l = citations.size();
        for (; i < l; i++) {
            if (citations[l - i - 1] <= i) {
                break;
            }
        }
        return i;
    }
};