class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        auto ptr = upper_bound(matrix.begin(), matrix.end(), vector<int>{target}, [](const vector<int> &a, const vector<int> &b){
            return a[0] < b[0];
        });
        if (ptr == matrix.begin()) return false;
        ptr--;
        return binary_search((*ptr).begin(), (*ptr).end(), target);
    }
};