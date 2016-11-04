class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> table;
        for (int n: nums) {
            auto i = table.find(n);
            if (i == table.end()) {
                table.insert(i, make_pair(n, 1));
            } else {
                i->second++;
            }
        }
        vector<pair<int, int>> lst;
        lst.reserve(table.size());
        for (auto p: table) {
            lst.push_back(make_pair(p.second, p.first));
        }
        make_heap(lst.begin(), lst.end());
        vector<int> res;
        res.reserve(k);
        for (;k > 0 && !lst.empty(); k--) {
            res.push_back(lst.front().second);
            pop_heap(lst.begin(), lst.end());
            lst.pop_back();
        }
        return res;
    }
};