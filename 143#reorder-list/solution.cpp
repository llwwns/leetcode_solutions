/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode *left;
    void link(ListNode *right) {
        if (right != NULL) {
            link(right->next);
            if (left == NULL) {
                return;
            }
            if (left == right || left->next == right) {
                right->next = NULL;
                left = NULL;
                return;
            }
            right->next = left->next;
            left->next = right;
            left = right->next;
            
        }
    }
public:
    void reorderList(ListNode *head) {
        left = head;
        link(head);
    }
};