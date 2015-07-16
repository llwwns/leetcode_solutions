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
    ListNode* insertionSortList(ListNode* head) {
        ListNode h2(-2147483648);
        ListNode* p = head, *q, *r = &h2, *s, *t;
        for (;p != NULL; p = q) {
            q = p->next;
            for  (s = r, t = r->next;r != NULL; s = t, t = t->next) {
                if (s->val <= p->val && t == NULL || t->val >= p->val) {
                    s->next = p;
                    p->next = t;
                    break;
                }
            }
        }
        return h2.next;
    }
};