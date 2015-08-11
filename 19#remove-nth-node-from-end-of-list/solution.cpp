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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 1 || head == NULL) return head;
        ListNode h(0);
        h.next = head;
        ListNode *p = head, *q = &h;
        for (; p != NULL; p = p->next) {
            if (n > 0) {
                n--;
            } else {
                q = q->next;
            }
        }
        p = q->next;
        delete p;
        q->next = p->next;
        return h.next;
    }
};