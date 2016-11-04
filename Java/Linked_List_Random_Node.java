/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    private ListNode list;
    private int list_size;
    private Random random = new Random();
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        list = head;
        list_size = 0;
        while (head != null) {
            list_size ++;
            head = head.next;
        }
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int index = random.nextInt(list_size);
        ListNode ptr = list;
        while (index > 0) {
            ptr = ptr.next;
            index --;
        }
        return ptr.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
