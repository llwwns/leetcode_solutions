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
    TreeNode *a, *b;
    bool search(TreeNode* root) {
        if (root == NULL) return false;
        bool t = (root == a || root == b);
        bool a = search(root->left);
        if (t && a) throw root;
        bool b = search(root->right);
        if (t && b || a && b) throw root;
        return t || a || b;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        a = p; b = q;
        try{
            search(root);
        } catch(TreeNode *p) {
            return p;
        }
        return NULL;
    }
};