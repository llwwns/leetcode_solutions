class Solution {
    unsigned int gcd(unsigned int u, unsigned int v)
    {
      int shift;
      if (u == 0) return v;
      if (v == 0) return u;
      for (shift = 0; ((u | v) & 1) == 0; ++shift) {
             u >>= 1;
             v >>= 1;
      }
      while ((u & 1) == 0)
        u >>= 1;
      do {
           while ((v & 1) == 0)
               v >>= 1;
           if (u > v) {
             unsigned int t = v; v = u; u = t;}
           v = v - u;
         } while (v != 0);
      return u << shift;
    }
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len <= 1 || k % len == 0) return;
        k = (((-k)%len) + len) % len;
        int i, t, s = 0, r, l;
        l = gcd(len, k);
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