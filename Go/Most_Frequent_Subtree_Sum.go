/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func subTreeSum(counter map[int]int, root *TreeNode) int{
    if root == nil {
        return 0
    }
    sum := root.Val + subTreeSum(counter, root.Left) + subTreeSum(counter, root.Right)
    if cnt,exists := counter[sum]; exists {
        counter[sum] = cnt+1
    } else {
        counter[sum] = 1
    }
    return sum
}

func findFrequentTreeSum(root *TreeNode) []int {
    counter := make(map[int]int)
    _ = subTreeSum(counter, root)
    max_cnt := 0
    var ret []int
    for _, cnt := range counter {
        if cnt > max_cnt {
            max_cnt = cnt
        }
    }
    for k, cnt := range counter {
        if cnt == max_cnt {
            ret = append(ret, k)
        }
    }
    return ret
}
