/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL) return;
        root->next = NULL;
        TreeLinkNode t(0);
        TreeLinkNode *p, *q, *r;
        for (p = root; p->left != NULL; p = p->left) {
            r = &t;
            for (q = p; q != NULL; q = q->next) {
                r->next = q->left;
                q->left->next = q->right;
                r = q->right;
            }
            r->next = NULL;
        }
    }
};