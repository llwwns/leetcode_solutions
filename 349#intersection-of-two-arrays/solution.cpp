class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        auto p1 = nums1.begin();
        auto e1 = nums1.end();
        auto p2 = nums2.begin();
        auto e2 = nums2.end();
        vector<int> lst;
        while (p1 != e1 && p2 != e2) {
            if (*p1 == *p2) {
                if (lst.empty() || lst.back() != *p1)
                lst.push_back(*p1);
                p1++;
                p2++;
            } else if (*p1 > *p2) {
                p2++;
            } else {
                p1++;
            }
        }
        return lst;
    }
};