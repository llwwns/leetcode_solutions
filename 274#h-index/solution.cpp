class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int i = 0, l = citations.size();
        for (; i < l; i++) {
            if (citations[i] <= i) {
                break;
            }
        }
        return i;
    }
};