/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    ListNode *c;
    int len;
    TreeNode* makeBST(int i) {
        if (i <= len) {
            TreeNode *p = new TreeNode(0);
            p->left = makeBST(i << 1);
            p->val = c->val;
            c = c->next;
            p->right = makeBST((i << 1) + 1);
            return p;
        }
        return NULL;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        c = head;
        len = 0;
        while (head != NULL) {head = head->next;len++;}
        return makeBST(1);
    }
};