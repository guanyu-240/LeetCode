/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) return NULL;
        RandomListNode *cur = head;
        // make a copy of every node after every node
        while (cur != NULL) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        // modify the random pointer of every new copied node
        cur = head;
        RandomListNode *next = NULL;
        while (cur != NULL) {
            next = cur->next;
            next->random = cur->random == NULL ? NULL : cur->random->next;
            cur = next->next;
        }
        
        // get all the copied nodes and create a new list
        RandomListNode *newHead = NULL;
        RandomListNode *ptr = newHead;
        cur = head;
        while (cur != NULL) {
            next = cur->next;
            cur->next = next->next;
            cur = cur->next;
            if (newHead == NULL) {newHead = next;}
            else {ptr->next = next;}
            ptr = next;
        }
        return newHead;
    }
};
