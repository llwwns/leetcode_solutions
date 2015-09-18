/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 class BSTIterator {
public:
    stack<TreeNode*> s;
    TreeNode* p;
    BSTIterator(TreeNode *root) {
        p = root;
        if (p != NULL) {
            while (p->left != NULL) {
                s.push(p);
                p = p->left;
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p != NULL;
    }

    /** @return the next smallest number */
    int& next() {
        TreeNode *q;
        int& res = p->val;
        while (true) {
            while(true) {
                if (p->right != NULL) {
                    s.push(p);
                    p = p->right;
                    break;
                } else {
                    while(true) {
                        if (s.empty()) {
                            p = NULL;
                            return res;
                        }
                        q = s.top();
                        if (p == q->left) {
                            p = q;
                            s.pop();
                            return res;
                        } else {
                            p = q;
                            s.pop();
                        }
                    }
                }
            }
            while (p->left != NULL) {
                s.push(p);
                p = p->left;
            }
            return res;
        }
    }
};
class Solution {
public:
    void recoverTree(TreeNode* root) {
        BSTIterator itr(root);
        int *a = &itr.next();
        int last_val = *a;
        int *b = a, *c = NULL, *p, *d = NULL;
        while (itr.hasNext()) {
            p = &itr.next();
            if (*p < last_val) {
                if (c == NULL) {
                    c = p;
                } else {
                    d = p;
                    break;
                }
            }
            if (c == NULL) {
                b = p;
            }
            last_val = *p;
        }
        if (d != NULL) swap(*d, *b);
        else if(c != NULL) swap(*b, *c);
    }
};