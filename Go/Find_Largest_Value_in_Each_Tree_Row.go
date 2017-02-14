/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func updateRes(res *[]int, root *TreeNode, row int) {
    if root == nil {
        return
    }
    if row >= len(*res) {
        *res = append(*res, root.Val);
    } else {
        if root.Val > (*res)[row] {
            (*res)[row] = root.Val;
        }
    }
    updateRes(res, root.Left, row+1);
    updateRes(res, root.Right, row+1);
}
func largestValues(root *TreeNode) []int {
    var res []int
    updateRes(&res, root, 0)
    return res
}
