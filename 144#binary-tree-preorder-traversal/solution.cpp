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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *p, *q;
        p = root;
        while (true) {
            ans.push_back(p->val);
            if (p->left != NULL) {
                s.push(p);
                p = p->left;
            } else if (p->right != NULL) {
                s.push(p);
                p = p->right;
            } else {
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
                        s.pop();
                    }
                }
            }
        }
    }
};