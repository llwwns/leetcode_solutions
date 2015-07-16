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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) return NULL;
        ListNode *p = head->next, *q = head;
        while (true) {
            while (p != NULL && p->val == val) {
                q->next = p->next;
                delete p;
                p = q->next;
            }
            if (p == NULL) break;
            q = p;
            p = p->next;
        }
        if (head->val == val) {
            p = head;
            head = head->next;
            delete p;
        }
        return head;
    }
};