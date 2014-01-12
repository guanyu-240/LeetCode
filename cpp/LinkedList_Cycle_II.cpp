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
    /*
    At first, a fast ptr and a slow ptr to detect whether cycle exists.
    When finding an collision point(Let it be c)
    Steps passed by slow ptr: x
    Steps passed by fast ptr: 2x
    x % LOOP_SIZE = 0
    slow ptr has k steps to reach the loop start
    Assume loop start is y steps before the beginning
    We get (2x + k - y) % LOOP_SIZE = 0
    Since x % LOOP_SIZE = 0
    We get (k - y) % LOOP_SIZE = 0
    2 possibilities:
    k = y
    k - y = m * LOOP_SIZE (k = m * LOOP_SIZE + y)
    Therefore if a pointer move k steps from the start, the pointer will also point to the start of the loop
    */
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
