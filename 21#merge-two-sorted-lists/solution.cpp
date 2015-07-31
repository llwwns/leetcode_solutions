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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode head(0);
        ListNode *p = &head;
        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                p->next = a;
                p = a;
                a = a->next;
            } else {
                p->next = b;
                p = b;
                b = b->next;
            }
        }
        if (a == NULL) a = b;
        while (a != NULL) {
            p->next = a;
            p = a;
            a = a->next;
        }
        p->next = NULL;
        return head.next;
    }
};