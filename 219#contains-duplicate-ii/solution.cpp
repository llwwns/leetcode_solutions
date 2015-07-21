class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;
        arr.reserve(nums.size());
        for (int i : nums) {
            arr.emplace_back(i, arr.size());
        }
        sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b){
            return a.first < b.first || a.first == b.first && a.second < b.second;
        });
        for (int i = arr.size() - 1; i > 0; i--) {
            if (arr[i].first == arr[i-1].first && arr[i].second - arr[i-1].second <= k) {
                return true;
            }
        }
        return false;
    }
};