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
        vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return vector<int>();
        stack<TreeNode*> s;
        vector<int> ans;
        TreeNode *p, *q;
        p = root;
        while (true) {
            while (p->left != NULL) {
                s.push(p);
                p = p->left;
            }
            while(true) {
                ans.push_back(p->val);
                if (p->right != NULL) {
                    s.push(p);
                    p = p->right;
                    break;
                } else {
                    while(true) {
                        if (s.empty()) {
                            return ans;
                        }
                        q = s.top();
                        if (p == q->left) {
                            p = q;
                            s.pop();
                            break;
                        } else {
                            p = q;
                            s.pop();
                        }
                    }
                }
            }
        }
    }
};