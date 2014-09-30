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
        int n = 0;
        ListNode ptr = head;
        while (ptr != null) {
            n ++;
            ptr = ptr.next;
        }
        return sortListRecursively(head, n);
    }
    
    private ListNode sortListRecursively(ListNode head, int n){
        if (n <= 1) return head;
        ListNode ptr = head;
        int len = 1;
        while (len < n/2) {
            ptr = ptr.next;
            len ++;
        }
        ListNode secondHalf = ptr.next;
        ptr.next = null;
        return mergeLists(sortListRecursively(head, n/2), sortListRecursively(secondHalf, n-n/2));
    }
    
    private ListNode mergeLists(ListNode h1, ListNode h2){
        ListNode ret = null, retPtr = null, ptr1 = h1, ptr2 = h2;
        while (ptr1 != null && ptr2 != null) {
            if (ptr1.val < ptr2.val) {
                if (retPtr != null) retPtr.next = ptr1;
                retPtr = ptr1;
                ptr1 = ptr1.next;
            }
            else {
                if (retPtr != null) retPtr.next = ptr2;
                retPtr = ptr2;
                ptr2 = ptr2.next;
            }
            if (ret == null) ret = retPtr;
        }
        if (ptr1 != null) retPtr.next = ptr1;
        if (ptr2 != null) retPtr.next = ptr2;
        return ret;
    }
}
