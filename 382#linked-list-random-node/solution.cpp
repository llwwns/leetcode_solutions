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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* p;
    int len;
    Solution(ListNode* head) {
        p = head;
        len = 0;
        ListNode *q = head;
        for (;head != NULL; q = head, head = head->next) {
            len++;
        }
        if (len > 0) {
            q->next = p;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if (len > 0) {
            int i = rand() % len;
            for (;i > 0; i--) {
                p = p->next;
            }
            return p->val;
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */