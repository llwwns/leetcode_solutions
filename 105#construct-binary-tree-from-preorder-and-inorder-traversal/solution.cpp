/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include <algorithm>
class Solution {
public:
    template<class Itr>
    TreeNode* build(Itr pl, Itr pr, Itr il, Itr ir) {
        if (pl == pr) return NULL;
        TreeNode* p = new TreeNode(*pl);
        Itr r = find(il, ir, *pl);
        p->left = build(pl + 1, pl + 1 + (r - il), il, r);
        p->right = build(pl + 1 + (r - il), pr, r + 1, ir);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder.data(), preorder.data() + preorder.size(), inorder.data(), inorder.data() + preorder.size());
    }
};