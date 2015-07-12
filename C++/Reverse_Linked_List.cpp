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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        reverseListHelper(head, &newHead);
        return newHead;
    }
    ListNode* reverseListHelper(ListNode* head, ListNode **newHead) {
        if (head == NULL) return NULL;
        if (head->next == NULL) {
            *newHead = head;
        }
        else {
            reverseListHelper(head->next, newHead)->next = head;
            head->next = NULL;
        }
        return head;
    }
};
