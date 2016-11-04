class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();;
        int i, j, m = 0, v;
        for (i = 0; i < len - 1; i++) {
            if (height[i] == 0) {
                continue;
            }
            int l = m / height[i];
            for (j = i + l; j < len; j++) {
                v = (j - i) * min(height[j], height[i]);
                if (v > m) m = v;
            }
        }
        return m;
    }
};