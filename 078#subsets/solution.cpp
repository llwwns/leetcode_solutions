class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<vector<int>>{vector<int>()};
        }
        int a = nums.back();
        nums.pop_back();
        auto lst = subsets(nums);
        auto lst2 = lst;
        for (auto &e : lst2) {
            e.push_back(a);
        }
        lst.insert(lst.end(), lst2.begin(), lst2.end());
        return lst;
    }
};