/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; next = null; }
 * }
 */
/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
        int len = 0;
        ListNode ptr = head;
        while (ptr != null) {
            len ++;
            ptr = ptr.next;
        }
        if (len == 0) return null;
        return solve(head, len);
    }
    
    private TreeNode solve(ListNode head, int len) {
        if (len == 0) return null;
        int index = 1;
        ListNode ptr = head;
        while (index <= (len-1)/2) {
            ptr = ptr.next;
            index ++;
        }
        TreeNode root = new TreeNode(ptr.val);
        root.left = solve(head, index-1);
        root.right =  solve(ptr.next, len-index);
        return root;
    }
}
