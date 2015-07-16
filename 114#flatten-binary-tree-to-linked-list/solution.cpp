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
    TreeNode* solve(TreeNode* root) {
        if (root->left == NULL && root->right == NULL) return root;
        if (root->left == NULL) return solve(root->right);
        TreeNode *p = solve(root->left);
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
        return p->right == NULL ? p :solve(p->right);
        
    }
    void flatten(TreeNode* root) {
        if (root == NULL) return;
        solve(root);
    }
};