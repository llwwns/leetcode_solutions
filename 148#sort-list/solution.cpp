/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    tuple<ListNode*, ListNode*> mergeFixedLength(ListNode* a, int l) {
        ListNode* b;
        ListNode head(0);
        ListNode *p = &head, *q;
        int la = 0, lb = 0;
        for (b = a; b != NULL && la < l; la++, b = b->next);
        for (q = b; q != NULL && lb < l; lb++, q = q->next);
        if (la < l || b == NULL) return tuple<ListNode*, ListNode*>(a, NULL);
        la = l;
        while (la > 0 && lb > 0) {
            if (a->val < b->val) {
                p->next = a;
                p = a;
                a = a->next;
                la--;
            } else {
                p->next = b;
                p = b;
                b = b->next;
                lb--;
            }
        }
        if (la == 0) a = b, la = lb;
        while (la > 0) {
            p->next = a;
            p = a;
            a = a->next;
            la--;
        }
        p->next = q;
        return make_tuple(head.next, p);
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *p = head, *q;
        for (int l = 1; get<1>(tie(p, q) = mergeFixedLength(p, l)) != NULL; l <<= 1) {
            do {
                tie(q->next, q) = mergeFixedLength(q->next, l);
            } while (q != NULL);
        }
        return p;
    }
};
