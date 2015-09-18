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
    bool first;
    int last_value;
    void check(TreeNode* root) {
        if (root == NULL) return;
        check(root->left);
        if (!first && last_value >= root->val) throw 1;
        first = false;
        last_value = root->val;
        check(root->right);
    }
    bool isValidBST(TreeNode* root) {
        first = true;
        try{
            check(root);
        } catch(int) {
            return false;
        }
        return true;
    }
};