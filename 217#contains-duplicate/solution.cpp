class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int *arr = nums.data();
        for (int i = nums.size() - 1; i > 0; i--) {
            if (arr[i] == arr[i-1]) {
                return true;
            }
        }
        return false;
    }
};