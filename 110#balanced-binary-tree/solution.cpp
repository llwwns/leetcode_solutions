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
    int check(TreeNode* root) {
        if (root == NULL) return 0;
        int ld = check(root->left);
        int rd = check(root->right);
        if (ld < rd - 1 || ld > rd + 1) {
            throw 0;
        }
        return max(ld, rd) + 1;
    }
    bool isBalanced(TreeNode* root) {
        try{
            check(root);
        } catch (int) {
            return false;
        }
        return true;
    }
};