/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
    if k <= 0 {
        return nil
    }
    
    ret := make([]*ListNode, k)
    
    n := 0
    ptr := root
    for ptr != nil {
        n ++
        ptr = ptr.Next
    }
    m := n / k
    remain := n % k
    
    ptr = root
    head := root
    i := 1
    j := 0
    for ptr != nil {
        if i < m {
            i ++
            ptr = ptr.Next
        } else {
            if remain > 0 {
                if i == m {
                    ptr = ptr.Next
                }
                remain --
            }
            ret[j] = head
            head = ptr.Next
            ptr.Next = nil
            ptr = head
            j ++
            i = 1
        }
    }
    
    for j < k {
        ret[j] = nil
        j ++
    }
    return ret
}
