class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int *arr = nums.data();
        int len = nums.size();
        if (len <= 2) return len;
        int i, j = 2, k = arr[0];
        for (i = 2; i < len; i++) {
            if (arr[i] != arr[i-1] || arr[i] != k) {
                k = arr[i-1];
                arr[j++] = arr[i];
            } else {
                k = arr[i-1];
            }
            
        }
        return j;
    }
};