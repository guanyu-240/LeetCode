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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 0, lenB = 0;
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != NULL) {
            ++ lenA;
            ptrA = ptrA->next;
        }
        while (ptrB != NULL) {
            ++ lenB;
            ptrB = ptrB->next;
        }
        ptrA = headA;
        ptrB = headB;
        int diff = lenA - lenB;
        while (diff != 0) {
            if (diff > 0) {
                ptrA = ptrA->next;
                diff --;
            }
            else {
                ptrB = ptrB->next;
                diff ++;
            }
        }
        while (ptrA != NULL && ptrB != NULL) {
            if (ptrA == ptrB) return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        return NULL;
    }
};
