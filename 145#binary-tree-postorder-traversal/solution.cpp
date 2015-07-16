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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *p, *q;
        p = root;
        while (true) {
            while (true) {
                while (p->left != NULL) {
                    s.push(p);
                    p = p->left;
                }
                if (p->right != NULL) {
                    s.push(p);
                    p = p->right;
                } else {
                    break;
                }
            }
            ans.push_back(p->val);
            while (true) {
                if (s.empty()) {
                    return ans;
                }
                q = s.top();
                if (p == q->left && q->right != NULL) {
                    p = q->right;
                    break;
                } else {
                    p = q;
                    ans.push_back(p->val);
                    s.pop();
                }
            }
        }
    }
};