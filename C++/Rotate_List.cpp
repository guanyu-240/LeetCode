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
    ListNode *rotateRight(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (head == NULL) {
            return head;
        }
        ListNode *newTail = head, *tail = head;
        /*
        The following loop does not directly fetch the tail of the original list and the new list.
        It tries to find the distance in the original list.
        And finally advance them together and move them to the right locations
        */
        for (int i = 1; i <= k; i ++){
            if (tail->next == NULL){
                tail = head;
            }
            else {
                tail = tail->next;
            }
        }
        if (newTail == tail) return head;  // indicating no need to do any rotations
        while (tail->next != NULL) {        
            newTail = newTail->next;
            tail = tail->next;
        }
        ListNode *ret = newTail->next;
        newTail->next = NULL;
        tail->next = head;
        return ret;
    }
};
