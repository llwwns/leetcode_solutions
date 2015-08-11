/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class UniqueBST {
public:
    vector<TreeNode*> make(int l, int r) {
        if (l > r) return vector<TreeNode*>{NULL};
        if (l == r) return vector<TreeNode*>{new TreeNode(l)};
        vector<TreeNode*> ans;
        for (int i = l; i <= r; i++) {
            auto a = make(l, i-1);
            auto b = make(i + 1, r);
            ans.reserve(a.size() * b.size());
            for (auto pl : a) {
                for (auto pr : b) {
                    TreeNode *p = new TreeNode(i);
                    p->left = pl;
                    p->right = pr;
                    ans.push_back(p);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nums;
    vector<char> opts;
    int calc(TreeNode *p) {
        int l = p->left == NULL ? nums[p->val - 1] : calc(p->left);
        int r = p->right == NULL ? nums[p->val] : calc(p->right);
        switch (opts[p->val - 1]) {
        case '+':
            return l + r;
        case '-':
            return l - r;
        case '*':
            return l * r;
        }
    }
    vector<int> diffWaysToCompute(string input) {
        int n = 0;
        nums.clear();
        opts.clear();
        for (char s : input) {
            if (s <= '9' && s >= '0') {
                n = n * 10 + (s - '0');
            } else {
                nums.push_back(n);
                n = 0;
                opts.push_back(s);
            }
        }
        if (opts.empty()) return vector<int>{n};
        nums.push_back(n);
        auto lst = UniqueBST().make(1, opts.size());
        vector<int> ret;
        ret.reserve(lst.size());
        for (auto p : lst) {
            ret.push_back(calc(p));
        }
        return ret;
    }
};