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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode *p = headA;
        for (; p->next != NULL; p = p->next);
        p->next = headA;
        ListNode *p1 = headB, *p2 = headB;
        while (p1 != NULL && p1->next != NULL) {
            p1 = p1->next->next;
            p2 = p2->next;
            if (p1 == p2) {
                while (p1 != headB) {
                    p1 = p1->next;
                    headB = headB->next;
                }
                p->next = NULL;
                return headB;
            }
        }
        p->next = NULL;
        return NULL;
    }
};