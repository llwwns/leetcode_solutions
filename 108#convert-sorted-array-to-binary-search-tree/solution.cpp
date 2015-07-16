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
    int *arr;
    int len, c;
    TreeNode* makeBST(int i) {
        if (i <= len) {
            TreeNode *p = new TreeNode(0);
            p->left = makeBST(i << 1);
            p->val = arr[c++];
            p->right = makeBST((i << 1) + 1);
            return p;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        arr = nums.data();
        len = nums.size();
        c = 0;
        return makeBST(1);
    }
};