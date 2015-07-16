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
    bool calc(TreeNode* root, int sum) {
        if (root->left == NULL && root->right == NULL) {
            return root->val == sum;
        }
        sum -= root->val;
        if (root->left == NULL) return calc(root->right, sum);
        if (root->right == NULL) return calc(root->left, sum);
        return calc(root->left, sum) || calc(root->right, sum);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL) {
            return false;
        }
        return calc(root, sum);
    }
};