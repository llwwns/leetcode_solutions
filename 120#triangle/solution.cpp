class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size();
        if (len == 0) return 0;
        vector<int> v(len + 2, 2147483647);
        v[1] = triangle[0][0];
        for (int i = 1; i < len; i ++) {
            for (int j = i; j >= 0; j--) {
                v[j+1] = min(v[j+1], v[j]) + triangle[i][j];
            }
        }
        return *min_element(v.begin() + 1, v.end());
    }
};