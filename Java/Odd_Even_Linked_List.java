/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode odd = head, head_even = head.next, even = head_even;
        while (even != null){
            odd.next = even.next;
            even.next = even.next != null ? even.next.next : null;
            odd = odd.next != null ? odd.next : odd;
            even = even.next;
        }
        odd.next = head_even;
        return head;
    }
}
