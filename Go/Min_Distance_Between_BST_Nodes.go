/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */



func minTwoInt(x int, y int) int{
    if x < y {
        return x
    } else {
        return y
    }
}

func minDiffInBST(root *TreeNode) int {
    minDiff := 1 << 32 - 1
    var visited *TreeNode
    traverse(root, &visited, &minDiff)
    return minDiff
}

func traverse(root *TreeNode, visited **TreeNode, minDiff *int) {
    if root == nil {
        return
    }
    traverse(root.Left, visited, minDiff)
    if *visited != nil {
        *minDiff = minTwoInt(*minDiff, root.Val-(*visited).Val)
        if *minDiff == 1 {
            return
        }
    }
    *visited = root
    traverse(root.Right, visited, minDiff)
}
