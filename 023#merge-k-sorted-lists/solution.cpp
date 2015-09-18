/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode head(0);
        ListNode *p = &head;
        while (a != NULL && b != NULL) {
            if (a->val < b->val) {
                p->next = a;
                p = a;
                a = a->next;
            } else {
                p->next = b;
                p = b;
                b = b->next;
            }
        }
        if (a == NULL) a = b;
        while (a != NULL) {
            p->next = a;
            p = a;
            a = a->next;
        }
        p->next = NULL;
        return head.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode **listp = lists.data();
        int listSize = lists.size();
        if (listSize == 0) return NULL;
        int left;
        while (listSize > 1) {
            left = 0;
            while (left + 1 < listSize) {
                listp[left] = mergeTwoLists(listp[left++], listp[--listSize]);
            }
        }
        return *listp;
    }
};