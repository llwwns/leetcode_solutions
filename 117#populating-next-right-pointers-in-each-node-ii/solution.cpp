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
        TreeLinkNode *p = root, *q, *r;
        while(p != NULL) {
            r = &t;
            do {
                if (p->left != NULL) {
                    r->next = p->left;
                    r = r->next;
                }
                if (p->right != NULL) {
                    r->next = p->right;
                    r = r->next;
                }
                p = p->next;
            } while (p != NULL);
            p = t.next;
            t.next = NULL;
        }
    }
};