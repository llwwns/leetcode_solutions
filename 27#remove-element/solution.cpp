class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        auto i = nums.begin();
        auto j = i;
        while (i != nums.end()) {
            if (*i != val) *(j++) = *i;
            i++;
        }
        return j - nums.begin();
    }
};