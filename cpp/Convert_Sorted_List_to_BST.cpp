/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = 0;
        ListNode *ptr = head;
        while (ptr != NULL) {
            len ++;
            ptr = ptr->next;
        }
        return solve(head, len);
    }
    TreeNode *solve(ListNode *head, int len){
        if (len == 0) return NULL;
        ListNode *ptr = head;
        int index = 0;
        while (index < len/2) {
            ptr = ptr->next;
            index ++;
        }
        TreeNode *root = new TreeNode(ptr->val);
        root->left = solve(head, index);
        root->right = solve(ptr->next, len - index - 1);
    }
};
