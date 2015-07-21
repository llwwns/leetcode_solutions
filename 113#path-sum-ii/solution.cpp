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
    vector<vector<int>> ans;
    vector<int> cur;
    void calc(TreeNode* root, int sum) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL && root->val == sum) {
            cur.push_back(root->val);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        sum -= root->val;
        cur.push_back(root->val);
        calc(root->left, sum);
        calc(root->right, sum);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        calc(root, sum);
        return ans;
    }
};