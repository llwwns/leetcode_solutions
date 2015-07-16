class Solution {
public:
    void search(int l, int r) {
        
    }
    int findKthLargest(vector<int>& nums, int k) {
        int *arr = nums.data();
        int l = 0, r = nums.size();
        k--;
        while (true) {
            if (l == r - 1 && l == k) return arr[k];
            int v = arr[l];
            int i, j = l;
            for (i = l + 1; i < r; i++) {
                if (arr[i] > v) {
                    swap(arr[++j], arr[i]);
                }
            }
            if (j == k) return arr[l];
            swap(arr[l], arr[j]);
            if (j < k) l = j + 1;
            else r = j;
        }
    }
};