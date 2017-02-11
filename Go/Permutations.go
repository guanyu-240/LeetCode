func swap(nums[] int, x int, y int) {
    if x != y {
        tmp := nums[x]
        nums[x] = nums[y]
        nums[y] = tmp
    }
}

func permuteFrom(nums[] int, start int, n int, res *[][]int, cand []int) {
    if start == n {
        *res = append(*res, cand)
    }
    for i := start; i < n; i ++ {
        swap(nums, start, i)
        newCand := append(cand, nums[start])
        permuteFrom(nums, start+1, n, res, newCand)
        swap(nums, start, i)
    }
}
func permute(nums []int) [][]int {
    var res [][]int
    cand := make([]int, 0)
    permuteFrom(nums, 0, len(nums), &res, cand)
    return res
}
