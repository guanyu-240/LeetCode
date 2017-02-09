/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var tmp *TreeNode
func flatten_helper(root *TreeNode) *TreeNode {
    if root == nil || (root.Left == nil && root.Right == nil) {
        return root
    }
    if root.Left != nil {
        tmp = flatten_helper(root.Left)
        tmp.Right = root.Right
        root.Right = root.Left
        root.Left = nil
        if tmp.Right != nil {
            return flatten_helper(tmp.Right)
        } else {
            return tmp
        }
    } else {
        return flatten_helper(root.Right)
    }
}

func flatten(root *TreeNode)  {
    flatten_helper(root)
}
