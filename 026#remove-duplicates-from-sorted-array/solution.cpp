class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int *arr = nums.data();
        int len = nums.size();
        if (len == 0) return 0;
        int i, j = 1;
        for (i = 1; i < len; i++) {
            if (arr[i] != arr[i-1]) {
                arr[j++] = arr[i];
            }
        }
        return j;
    }
};