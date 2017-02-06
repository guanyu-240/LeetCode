/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func pathSumEndHere(root *TreeNode, sum int) int {
    if root == nil {
        return 0
    }else if root.Val == sum {
        return 1 + pathSumEndHere(root.Left, 0) + 
                    pathSumEndHere(root.Right, 0)
    } else {
        return pathSumEndHere(root.Left, sum-root.Val) + 
                pathSumEndHere(root.Right, sum-root.Val)
    }
}
func pathSum(root *TreeNode, sum int) int {
    if root == nil {
        return 0
    }
    return pathSum(root.Left, sum)+ pathSumEndHere(root, sum) + 
            pathSum(root.Right, sum)
}
