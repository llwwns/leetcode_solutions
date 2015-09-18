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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p, *q, *r;
        for (p = r = head, head = head->next; p != NULL && p->next != NULL; r = p, p = r->next) {
            q = p->next;
            r->next = q;
            p->next = q->next;
            q->next = p;
        }
        return head;
    }
};