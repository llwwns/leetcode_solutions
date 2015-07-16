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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        stack<TreeNode*> s1, s2;
        TreeNode* p;
        s1.push(root);
        vector<vector<int>> ans;
        vector<int> list;
        while (!s1.empty()) {
            do {
                p = s1.top();
                s1.pop();
                list.push_back(p->val);
                if (p->left != NULL) s2.push(p->left);
                if (p->right != NULL) s2.push(p->right);
            } while (!s1.empty());
            ans.push_back(list);
            list.clear();
            if (s2.empty()) {
                return ans;
            }
            do {
                p = s2.top();
                s2.pop();
                list.push_back(p->val);
                if (p->right != NULL) s1.push(p->right);
                if (p->left != NULL) s1.push(p->left);
            }while (!s2.empty());
            ans.push_back(list);
            list.clear();
        }
        return ans;
    }
};