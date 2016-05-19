class Solution {
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<vector<int>>{vector<int>()};
        }
        int a = nums.back(), c = 1;
        nums.pop_back();
        while(!nums.empty() && nums.back() == a) {
            c++;
            nums.pop_back();
        }
        auto lst = subsets(nums);
        auto lst2 = lst;
        vector<int> lsta;
        for (int i = 1; i <= c; i++) {
            for (auto &e : lst2) {
                e.push_back(a);
            }
            lst.insert(lst.end(), lst2.begin(), lst2.end());
        }
        return lst;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return subsets(nums);
    }
};