class Solution {
public:
    int jump(vector<int>& nums) {
        int mnow = 0, mnext = 0, step = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > mnow) {
                step++;
                mnow = mnext;
            }
            if (i + nums[i] > mnext) {
                mnext = i + nums[i];
            }
        }
        return step;
    }
};