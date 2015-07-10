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
    bool isPalindrome(ListNode* head) {
        int length = 0;
        ListNode* tmp = head;
        while (tmp != NULL) {
            length ++;
            tmp = tmp->next;
        }
        if (length == 0) return true;
        if (isPalHelper(head, 0, length)) return true;
        return false;
    }
    ListNode* isPalHelper(ListNode* head, int index, int length) {
        /* For list node with index i, 
           if sub-list[i, length-1-i] is a palindrome list, 
           returns the last node of this sub-list,
           otherwise returns NULL */
        if (length%2 == 0 && index == length/2-1){
            if (head->val == head->next->val) {
                return head->next;
            }
            else {
                return NULL;
            }
        }
        if (length%2 == 1 && index == length/2){
            return head;
        }
        ListNode* ret = isPalHelper(head->next, index+1, length);
        if (ret == NULL) return NULL;
        ret = ret->next;
        if (ret != NULL && head->val == ret->val) return ret;
        return NULL;
    }
};
