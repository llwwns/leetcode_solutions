class Solution {
public:
    vector<int> ori, cur;
    random_device rd;
    mt19937 g;
    Solution(vector<int> nums) : ori(nums), cur(nums), g(rd()) {
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return cur = ori;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        std::shuffle(cur.begin(), cur.end(), g);
        return cur;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */