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
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        while (p != NULL && p->next != NULL) {
            p = p->next->next;
            head = head->next;
            if (p == head) return true;
        }
        return false;
    }
};