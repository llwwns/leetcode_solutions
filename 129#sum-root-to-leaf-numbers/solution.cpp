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
    int sum;
    void calcSum(TreeNode* node, int num) {
        if (node == NULL) return;
        num = num * 10 + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += num;
        } else {
            calcSum(node->left, num);
            calcSum(node->right, num);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        calcSum(root, 0);
        return sum;
    }
};