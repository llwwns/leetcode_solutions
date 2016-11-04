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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode ret(0);
        ListNode *p = head, *t = &ret;
        bool dup = false;
        for (head = head->next; head != NULL; p = head, head = head->next) {
            if (p->val == head->val) {
                dup = true;
            } else {
                if (!dup) {
                    t->next = p;
                    t = p;
                }
                dup = false;
            }
        }
        if (!dup) {
            t->next = p;
            t = p;
        }
        t->next = NULL;
        return ret.next;
    }
};