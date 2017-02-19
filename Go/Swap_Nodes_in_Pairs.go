/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
var newHead *ListNode
func swapPairs(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    } else {
        newHead := head.Next
        head.Next = swapPairs(head.Next.Next)
        newHead.Next = head
        return newHead
    }
}
