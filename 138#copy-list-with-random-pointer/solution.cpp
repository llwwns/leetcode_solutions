/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode h2{0};
        RandomListNode* t2 = &h2;
        while(head != NULL) {
            t2->next = new RandomListNode(head->label);
            t2 = t2->next;
            map[head] = t2;
            t2->random = head->random;
            head = head->next;
        }
        for (t2 = h2.next; t2 != NULL; t2 = t2->next) {
            if (t2->random != NULL) {
                t2->random = map[t2->random];
            }
        }
        return h2.next;
    }
};