/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func checkAndUpdate(root *TreeNode, height int, bl_height *int, bl_value *int) {
    if root == nil {
        return
    }
    if height > *bl_height {
        *bl_value = root.Val
        *bl_height = height
    }
    checkAndUpdate(root.Left, height+1, bl_height, bl_value)
    checkAndUpdate(root.Right, height+1, bl_height, bl_value)
}
func findBottomLeftValue(root *TreeNode) int {
    bl_value,bl_height := 0, -1
    checkAndUpdate(root, 0, &bl_height, &bl_value)
    return bl_value
}
