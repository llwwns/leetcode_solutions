class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1 || k % len == 0) return;
        k = (((-k)%len) + len) % len;
        int i, t, s = 0, r, l;
        for (l = 1, i = (s + k) % len; i != s; l++, i = (i + k) % len);
        l = len / l;
        do {
            t = nums[s];
            i = s;
            while (true) {
                r = (i + k) % len;
                if (r == s) {
                    nums[i] = t;
                    break;
                }
                nums[i] = nums[r];
                i = r;
            }
            s++;
        } while(s < l);
    }
};