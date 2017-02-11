/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isMirror(r1 *TreeNode, r2 *TreeNode) bool{
    if r1 == nil && r2 == nil {
        return true
    } else if r1 != nil && r2 != nil {
        if r1.Val == r2.Val {
            if isMirror(r1.Right, r2.Left) {
                if isMirror(r1.Left, r2.Right) {
                    return true
                }
            }
        }
        return false
    } else {
        return false
    }
}
func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    } else {
        return isMirror(root.Left, root.Right)
    }
}
