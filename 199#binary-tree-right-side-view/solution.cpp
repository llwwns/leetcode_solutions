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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        vector<TreeNode*> lst{root}, tmp;
        TreeLinkNode *p;
        while(!lst.empty()) {
            ans.push_back(lst.back()->val);
            tmp = move(lst);
            lst.clear();
            for (auto p : tmp) {
                if (p->left != NULL) {
                    lst.push_back(p->left);
                }
                if (p->right != NULL) {
                    lst.push_back(p->right);
                }
            }
        }
        return ans;
    }
};