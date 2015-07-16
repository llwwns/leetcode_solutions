class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int len = nums.size(), *arr = nums.data();
        int i = 1, j = 0, sum = arr[0], m = len;
        while (i <= len) {
            if (sum < s) {
                sum += arr[i++];
            } else if (sum >= arr[j] + s && j + 1 < i) {
                sum -= arr[j++];
            } else {
                if (i - j < m) {
                    m = i - j;
                }
                sum += arr[i++];
            }
        }
        if (i > len && j == 0 && sum < s) return 0;
        return m;
    }
};