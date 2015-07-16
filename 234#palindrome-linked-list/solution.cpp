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
    bool isPalindrome(ListNode* head) {
        ListNode *p, *q, *r;
        int len = 0, i;
        for(p = head; p!=NULL; p=p->next) len++;
        if (len <= 1) return true;
        int l2 = len / 2;
        for (i = 0, p = head; i < (len >> 1); i++) p = p->next;
        if (len & 1 == 1) {
            p = p->next;
        }
        for (q = p, p = p->next, q->next = NULL; p != NULL; p = r) {
            r = p->next;
            p->next = q;
            q = p;
        }
        for (; q != NULL; q = q->next, head = head->next) {
            if (q->val != head->val) return false;
        }
        return true;
    }
};