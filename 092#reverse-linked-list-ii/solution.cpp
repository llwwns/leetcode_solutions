/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return NULL;
        ListNode *p, *q, *r, *b = NULL, *c = head;
        for (m--, n--; c != NULL && m > 0; m--, n--, b = c, c = c->next);
        p = c;
        r = c->next;
        for (q = p, p = p->next; p != NULL && n > 0; p = r, n--) {
            r = p->next;
            p->next = q;
            q = p;
        }
        if (b != NULL) b->next = q;
        else head = q;
        c->next = r;
        return head;
    }
};