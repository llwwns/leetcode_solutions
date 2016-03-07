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
    ListNode* oddEvenList(ListNode* head) {
        ListNode h[2]{0, 0};
        ListNode* t[2]{&h[0], &h[1]};
        for (int i = 0; head != NULL; head = head->next, i ^= 1) {
            t[i]->next = head;
            t[i] = head;
        }
        t[0]->next = h[1].next;
        t[1]->next = NULL;
        return h[0].next;
    }
};