/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null) return head;
        int len = 0;
        ListNode ptr = head;
        while (ptr != null) {
            len ++;
            ptr = ptr.next;
        }
        return solve(head, len);
    }
    public ListNode solve(ListNode head, int len) {
        if (len == 1) return head;
        ListNode ptr = head;
        int index = 1;
        while (index < len/2) {
            ptr = ptr.next;
            index ++;
        }
        ListNode h2 = solve(ptr.next, len-index);
        ptr.next = null;
        ListNode h1 = solve(head, index);
        return merge(h1, h2);
    }
    public ListNode merge(ListNode h1, ListNode h2) {
        ListNode ret = null;
        ListNode ptr = ret;
        ListNode ptr1 = h1, ptr2 = h2;
        while (ptr1 != null && ptr2 != null) {
            if (ptr1.val < ptr2.val) {
                if (ret == null) ret = ptr1;
                else ptr.next = ptr1;
                ptr = ptr1;
                ptr1 = ptr1.next;
            }
            else {
                if (ret == null) ret = ptr2;
                else ptr.next = ptr2;
                ptr = ptr2;
                ptr2 = ptr2.next;
            }
        }
        if (ptr1 != null) ptr.next = ptr1;
        if (ptr2 != null) ptr.next = ptr2;
        return ret;
    }
}
