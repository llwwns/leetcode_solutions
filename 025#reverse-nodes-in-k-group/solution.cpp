/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q, *r;
        for (q = p, p = p->next, q->next = NULL; p != NULL; p = r) {
            r = p->next;
            p->next = q;
            q = p;
        }
        return q;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k == 1) return head;
        ListNode list(0);
        list.next = head;
        ListNode *l = &list, *r = head, *rn, *ln;
        int i;
        for (i = 1; r != NULL; r = r->next, i++) {
            if (i == k) {
                i = 0;
                rn = r->next;
                r->next = NULL;
                ln = l->next;
                l->next = reverseList(ln);
                ln->next = rn;
                l = r = ln;
            }
        }
        return list.next;
    }
};