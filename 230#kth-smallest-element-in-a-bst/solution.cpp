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
    int c, _k;
    void get(TreeNode* root) {
        if (root == NULL) return;
        get(root->left);
        if (++c == _k) {
            throw root->val;
        }
        get(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        c = 0;
        _k = k;
        try {
            get(root);
        } catch(int v) {
            return v;
        }
        return 0;
    }
};