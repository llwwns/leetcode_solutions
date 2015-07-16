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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return vector<vector<int>>();
        queue<TreeNode*> q;
        TreeNode* p;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        vector<int> list;
        while(true) {
            p = q.front();
            q.pop();
            if (p == NULL) {
                ans.push_back(list);
                q.push(NULL);
                if (q.front() == NULL) {
                    return ans;
                }
                list.clear();
            } else {
                list.push_back(p->val);
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            }
        }
        
    }
};