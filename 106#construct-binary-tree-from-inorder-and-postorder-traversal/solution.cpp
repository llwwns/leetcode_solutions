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
    template<class Itr>
    TreeNode* build(Itr il, Itr ir, Itr pl, Itr pr) {
        if (pl == pr) return NULL;
        TreeNode* p = new TreeNode(*(pr-1));
        Itr r = find(il, ir, *(pr-1));
        p->left = build(il, r, pl , pl + (r - il));
        p->right = build(r + 1, ir, pl  + (r - il), pr - 1);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder.data(), inorder.data() + inorder.size(), postorder.data(), postorder.data() + postorder.size());
    }
};