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
};