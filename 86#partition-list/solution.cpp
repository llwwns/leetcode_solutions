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
    ListNode* partition(ListNode* head, int x) {
        ListNode lhead(0), rhead(0);
        ListNode *left = &lhead, *right = &rhead;
        
        for (ListNode *ptr = head, *tmp; ptr != NULL; ptr = ptr->next) {
            if (ptr->val < x) {
                left->next = ptr;
                left = ptr;
            } else {
                right->next = ptr;
                right = ptr;
            }
        }
        right->next = NULL;
        left->next = rhead.next;
        return lhead.next;
    }
};