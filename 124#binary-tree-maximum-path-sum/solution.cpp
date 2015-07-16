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
    int max_value;
    int calc(TreeNode* root) {
        if (root == NULL) return -2147483648;
        int lv =calc(root->left), rv = calc(root->right);
        int mv = max(lv, rv);
        int with_root = mv > 0 ? mv + root->val : root->val;
        if (lv > 0 && rv > 0) with_root = max(with_root, lv + rv + root->val);
        if (with_root > max_value) max_value = with_root;
        return mv > 0 ? mv + root->val : root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) return 0;
        max_value = root->val;
        calc(root);
        return max_value;
    }
};