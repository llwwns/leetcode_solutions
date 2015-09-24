class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (nums.empty()) return "0";
        sort(nums.begin(), nums.end(), [](int a, int b) {
            auto sa = to_string(a), sb = to_string(b);
            return sa + sb > sb + sa;
        });
        if (nums[0] == 0) return "0";
        string s;
        for (int i : nums) {
            s.append(to_string(i));
        }
        return s;
    }
};