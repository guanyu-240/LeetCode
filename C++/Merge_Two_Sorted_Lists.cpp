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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *ptr1 = l1, *ptr2 = l2;
        ListNode *head = NULL, *prev = NULL, *cur = head;
        while (ptr1 != NULL || ptr2 != NULL) {
            cur = NULL;
            if (ptr1 != NULL && (ptr2 == NULL || (ptr2 != NULL && ptr1->val < ptr2->val))) {
                cur = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                cur = ptr2;
                ptr2 = ptr2->next;
            }
            if (head == NULL) head = cur;
            else prev->next = cur;
            prev = cur;
        }
        return head;
    }
};
