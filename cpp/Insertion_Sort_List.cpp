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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return NULL;
        ListNode *pre = head, *cur = head->next, *next = NULL, *ptr = NULL;
        while (cur != NULL) {
            next = cur->next;
            if (cur->val <= head->val){
                cur->next = head;
                head = cur;
                pre->next = next;
            }
            else {
                ptr = head;
                while (ptr != cur) {
                    if (ptr->val <= cur->val && ptr->next != cur && ptr->next->val > cur->val){
                        cur->next = ptr->next;
                        ptr->next = cur;
                        pre->next = next;
                        break;
                    }
                    ptr = ptr->next;
                }
                if (ptr == cur) {
                    pre = cur;
                }
            }
            cur = next;
        }
        return head;
    }
};
