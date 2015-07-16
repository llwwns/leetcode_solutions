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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        int len = 1, t;
        ListNode *p = head;
        while (p->next != NULL) {
            len++;
            p = p->next;
        }
        p->next = head;
        t = (-k - 1) % len + len;
        p = head;
        while (t > 0) {
            p = p->next;
            t--;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};