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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return head;
        ListNode *p, *q, *t;
        for (q = head, p = head->next; p != NULL;) {
            if (p->val == q->val) {
                t = p->next;
                delete p;
                q->next = p = t;
            } else {
                q = p;
                p = p->next;
            }
        }
        return head;
    }
};