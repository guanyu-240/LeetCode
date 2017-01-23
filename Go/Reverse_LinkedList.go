/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseListRec(head *ListNode, newHead **ListNode) *ListNode{
    if (head == nil || head.Next == nil) {
        *newHead = head;
    } else {
        reverseListRec(head.Next, newHead).Next = head
        head.Next = nil
    }
    return head
}
func reverseList(head *ListNode) *ListNode {
    ret := &ListNode{}
    reverseListRec(head, &ret)
    return ret
}
