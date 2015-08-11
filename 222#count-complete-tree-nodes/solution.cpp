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
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        TreeNode *q = root->right;
        int d = 1;
        for (root = root->left; root != NULL; root = root->left, q = q->right) {
            if (q == NULL) return -d;
            d++;
        }
        return d;
    }
    int count(TreeNode* root, int d) {
        if (d < 0) {
            int d2 = depth(root->left);
            if (d2 < 0) return count(root->left, d2) + (1 << (~d));
            return (1 << d2) + count(root->right, depth(root->right));
        } else {
            return (1 << d) - 1;
        }
    }
    int countNodes(TreeNode* root) {
        if (root == NULL) return 0;
        return count(root, depth(root));
    }
};