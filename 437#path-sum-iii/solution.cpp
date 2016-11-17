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
    vector<int> a;
public:
    int pathSum(TreeNode* root, int sum, bool started = false) {
        if (root == NULL) {
            return 0;
        }
        int r = 0;
        if (!started) {
            r += pathSum(root->left, sum, false) + pathSum(root->right, sum, false);
        }
        sum -= root->val;
        if (sum == 0) {
            r++;
        }
        r += pathSum(root->left, sum, true) + pathSum(root->right, sum, true);
        return r;
    }
};