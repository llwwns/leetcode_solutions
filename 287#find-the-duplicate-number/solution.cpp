class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size(), m, len = nums.size();
        int u, d;
        while (l + 1 < r) {
            m = (l + r) >> 1;
            d = u = 0;
            for (int i : nums) {
                if (i < m) d++;
                else if (i > m) u++;
            }
            if (u + d < len - 1) return m;
            if (d > m - 1) r = m;
            else l = m + 1;
        }
        return l;
    }
};