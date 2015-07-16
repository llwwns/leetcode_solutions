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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* p = new ListNode(0), *q;
        q = p;
        while(l1 != NULL && l2 != NULL) {
            t += l1->val + l2->val;
            p->next = new ListNode(t % 10);
            p = p->next;
            t /= 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l2 != NULL) {
            l1 = l2;
        }
        while (l1 != NULL) {
            t += l1->val;
            p->next = new ListNode(t % 10);
            p = p->next;
            t /= 10;
            l1 = l1->next;
        }
        if (t > 0) {
            p->next = new ListNode(t);
        }
        p = q->next;
        delete q;
        return p;
    }
};