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
    public void reorderList(ListNode head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (head == null) return;
        int len = 0;
        ListNode ptr = head;
        while (ptr != null) {
            len ++;
            ptr = ptr.next;
        }
        int secondHalfStart = (len % 2 == 0) ? len/2 + 1 : len/2 + 2;
        int index = 1;
        ptr = head;
        ListNode next = null;
        ListNode secondHalf = null;
        while (ptr != null) {
            next = ptr.next;
            if (index == secondHalfStart - 1) {
                ptr.next = null;
            }
            if (index >= secondHalfStart) {
                ptr.next = secondHalf;
                secondHalf = ptr;
            }
            ptr = next;
            index ++;
        }
        ptr = head; next = null;
        ListNode ptr2 = secondHalf, next2 = null;
        while (ptr != null && ptr2 != null) {
            next = ptr.next;
            next2 = ptr2.next;
            ptr.next = ptr2;
            ptr2.next = next;
            ptr = next;
            ptr2 = next2;
        }
    }
}
