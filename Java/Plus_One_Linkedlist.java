/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode plusOne(ListNode head) {
        if (head == null) return head;
        ListNode nine_start = null, pre_nine_start = null;  
        ListNode ptr = head, prev = null;
        while (true) {
            if (ptr.val == 9) {
                if (nine_start == null) {
                    nine_start = ptr;
                    pre_nine_start = prev;
                }
            }
            else {
                nine_start = pre_nine_start = null;
            }
            if (ptr.next == null) break;
            prev = ptr;
            ptr = ptr.next;
        }
        if (nine_start == null) { ptr.val ++; }
        else {
            if (nine_start == head) {
                head = new ListNode(1);
                head.next = nine_start;
            }
            if (pre_nine_start != null) pre_nine_start.val ++;
            while (nine_start != null) {
                nine_start.val = 0;
                nine_start = nine_start.next;
            }
        }
        return head;
    }
}
