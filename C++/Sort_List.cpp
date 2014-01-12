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
    ListNode *sortList(ListNode *head) {
        ListNode *ptr = head;
        int len = 0;
        while (ptr != NULL) {
            len ++;
            ptr = ptr->next;
        }
        if (len == 0) return NULL;
        return solve(head, len);
    }
    ListNode *solve(ListNode *head, int len){
        if (len == 1) return head;
        ListNode *ptr = head;
        int count = 1;
        while (count < len/2){
            ptr = ptr->next;
            count ++;
        }
        ListNode *h2 = solve(ptr->next, len - count);
        ptr->next = NULL;
        ListNode *h1 = solve(head, count);
        return merge(h1, h2);
    }
    ListNode *merge(ListNode *h1, ListNode *h2){
        ListNode *head = NULL;
        ListNode *ptr1 = h1, *ptr2 = h2;
        ListNode *ptr = head, *cand = NULL;
        while (ptr1 != NULL && ptr2 != NULL) {
            if (ptr1->val < ptr2->val) {
                cand = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                cand = ptr2;
                ptr2 = ptr2->next;
            }
            if (head == NULL) head = cand;
            else ptr->next = cand;
            ptr = cand;
        }
        if (ptr1 != NULL) ptr->next = ptr1;
        if (ptr2 != NULL) ptr->next = ptr2;
        return head;
    }
};
