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
        ListNode *start = head, *end = head;
        for (int i = 1; i <= k; i ++){
            if (end->next == NULL){
                end = head;
            }
            else {
                end = end->next;
            }
        }
        if (start == end) return head;
        while (end->next != NULL) {
            start = start->next;
            end = end->next;
        }
        ListNode *ret = start->next;
        start->next = NULL;
        end->next = head;
        return ret;
    }
};
