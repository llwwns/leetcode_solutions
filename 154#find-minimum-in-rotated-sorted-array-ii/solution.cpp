class Solution {
public:
    int findMin(vector<int>& nums) {
        return *max_element(nums.begin(), nums.end(), greater<int>());
    }
};