class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int* a = nums.data();
        int len = nums.size();
        if (len <= 1) return 0;
        if (a[0] > a[1]) return 0;
        if (a[len - 1] > a[len - 2]) return len - 1;
        int left = 1, right = len - 1, middle;
        while (left + 1 < right) {
            middle = (left >> 1) + (right >> 1) + (left&right&1);
            if (a[middle] > a[middle-1] && a[middle] > a[middle+1]) {
                return middle;
            }
            if (a[middle-1] > a[middle]) {
                right = middle;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};