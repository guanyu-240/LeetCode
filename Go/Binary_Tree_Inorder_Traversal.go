/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func inorderTraversal(root *TreeNode) []int {
    var ret []int
    if root == nil {
        return ret
    }
    st := list.New()
    node := root
    for node != nil || st.Len() > 0 {
        for node != nil {
            st.PushBack(node)
            node = node.Left
        }
        node = st.Remove(st.Back()).(*TreeNode)
        ret = append(ret, node.Val)
        node = node.Right
    }
    return ret
}
