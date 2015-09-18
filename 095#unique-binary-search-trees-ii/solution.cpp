/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
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
    vector<TreeNode*> generateTrees(int n) {
        return make(1, n);
    }
};