class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int* arr = nums.data();
        int len = nums.size();
        for (int i = len - 2; i >= 0; i--) {
            if (arr[i] != arr[len - 1]) {
                arr[i] = arr[len - 1];
                len -= 2;
            }
        }
        return *arr;
    }
};