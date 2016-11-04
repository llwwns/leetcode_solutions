int lowbit(int n) {
    return n & -n;
} 
class NumArray {
    vector<int> tree;
public:
    NumArray(vector<int> &nums) {
        tree.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) {
            tree[i] = nums[i - 1];
            for (int j = i - 1; j > i - lowbit(i); j -= lowbit(j)) {
                tree [i] += tree[j];
            }
        }
    }

    void update(int i, int val) {
        val -= i > 0 ? sumTo(i) - sumTo(i - 1) : sumTo(i);
        for (i++; i < tree.size(); i += lowbit(i)) {
            tree[i] += val;
        }
    }
    int sumTo(int i) {
        int sum = 0;
        for (i++; i > 0; i -= lowbit(i)) {
            sum += tree[i];
        }
        return sum;
    }

    int sumRange(int i, int j) {
        return i > 0 ? sumTo(j) - sumTo(i - 1) : sumTo(j);
    }
    
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);