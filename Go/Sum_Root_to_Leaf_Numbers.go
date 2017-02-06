/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumNumbersWithPred(root *TreeNode, pred int) int {
    if root == nil {
        return 0
    } else if root.Left == nil && root.Right == nil {
        return 10*pred + root.Val
    } else {
        return sumNumbersWithPred(root.Left, 10*pred+root.Val) +
                sumNumbersWithPred(root.Right, 10*pred+root.Val)
    }
}
func sumNumbers(root *TreeNode) int {
    return sumNumbersWithPred(root, 0)
}
