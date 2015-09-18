
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        int c = 1;
        for(int i : nums) {
            int j = target - i;
            auto v = hash.find(j);
            if (v != hash.end()) {
                return vector<int>{v->second, c};
            }
            hash[i] = c;
            c++;
        }
        return vector<int>();
    }
    
};