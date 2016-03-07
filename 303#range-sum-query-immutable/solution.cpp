class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int> &nums) {
        sum.reserve(nums.size());
        int s = 0;
        for (int i : nums) {
            s += i;
            sum.push_back(s);
        }
    }

    int sumRange(int i, int j) {
        return i > 0 ? sum[j] - sum[i - 1] : sum[j];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);