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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return;
        ListNode *secondHalf = NULL;
        int len = 1, index = 1, secondHalfStart = 1;
        ListNode *ptr = head, *next = NULL;
        while (ptr->next != NULL) {
            ptr = ptr->next;
            len ++;
        }
        ptr = head;
        secondHalfStart = (len%2==0) ? len/2+1 : len/2+2;
        while (ptr != NULL) {
            next = ptr->next;
            if (index == secondHalfStart - 1) ptr->next = NULL;
            if (index >= secondHalfStart) {
                ptr->next = (secondHalf == NULL ? NULL : secondHalf);
                secondHalf = ptr;
            }
            ptr = next;
            index ++;
        }
        
        // combine the first half and second half
        ListNode *ptr1 = head, *ptr2 = secondHalf, *next1 = NULL, *next2 = NULL;
        while (ptr1 != NULL && ptr2 != NULL) {
            next1 = ptr1->next;
            next2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = next1;
            ptr1 = next1;
            ptr2 = next2;
        }
    }
};
