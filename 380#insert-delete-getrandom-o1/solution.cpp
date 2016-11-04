class RandomizedSet {
    unordered_map<int, int> hash;
    vector<int> nums;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto itr = hash.find(val);
        if (itr == hash.end()) {
            hash[val] = nums.size();
            nums.push_back(val);
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto itr = hash.find(val);
        if (itr != hash.end()) {
            swap(nums[itr->second], nums.back());
            nums.pop_back();
            hash[nums[itr->second]] = itr->second;
            hash.erase(itr);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */