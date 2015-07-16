class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> ans(rowIndex);
        int *arr = ans.data();
        arr[0] = 1;
        for (int i = 1; i < rowIndex; i++) {
            vector<int> r(i + 1);
            arr[i] = 1;
            for (int j = i-1; j > 0; j--) {
                arr[j] = arr[j] + arr[j-1];
            }
        }
        return ans;
    }
};