class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.empty()) {
            return;
        }
        auto l = nums.begin();
        auto r = nums.rbegin();
        auto t = l;
        int len = nums.size();
        for (int i = 0; i < len ; i++) {
            if (*t == 0) {
                swap (*l++, *t++);
            } else if (*t == 2) {
                swap(*r++, *t);
            } else {
                t++;
            }
        }
    }
};