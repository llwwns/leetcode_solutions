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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) return ans;
        string path;
        vector<TreeNode*> s;
        TreeNode *p, *q;
        p = root;
        while (true) {
            while (true) {
                while (p->left != NULL) {
                    s.push_back(p);
                    p = p->left;
                }
                if (p->right != NULL) {
                    s.push_back(p);
                    p = p->right;
                } else {
                    break;
                }
            }
            path.clear();
            for (TreeNode* n: s) {
                path += to_string(n->val);
                path += "->";
            }
            path += to_string(p->val);
            ans.push_back(move(path));
            while (true) {
                if (s.empty()) {
                    return ans;
                }
                q = s.back();
                if (p == q->left && q->right != NULL) {
                    p = q->right;
                    break;
                } else {
                    p = q;
                    s.pop_back();
                }
            }
        }
    }
};