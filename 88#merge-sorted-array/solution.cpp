class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> t;
        t.reserve(m + n);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                t.push_back(nums1[i++]);
            } else {
                t.push_back(nums2[j++]);
            }
        }
        while (i < m) {
            t.push_back(nums1[i++]);
        }
        while (j < n) {
            t.push_back(nums2[j++]);
        }
        nums1 = move(t);
    }
};