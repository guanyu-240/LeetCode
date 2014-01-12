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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) return false;
        ListNode *faster = head;
        ListNode *slower = head;
        while (faster != NULL && faster->next != NULL) {
            faster = faster->next->next;
            slower = slower->next;
            if (faster == slower) {
                return true;
            }
        }
        return false;
    }
};
