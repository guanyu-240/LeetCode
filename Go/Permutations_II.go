func swap(nums[] int, x int, y int) {
    if x != y {
        tmp := nums[x]
        nums[x] = nums[y]
        nums[y] = tmp
    }
}

func permuteFrom(nums[] int, start int, n int, res *[][]int, cand []int, cand_idx int) {
    if start == n {
        a_res := make([]int, n)
        copy(a_res, cand)
        *res = append(*res, a_res)
        return
    }
    used := make(map[int]bool)
    for i := start; i < n; i ++ {
        if !used[nums[i]] {
            used[nums[i]] = true
            swap(nums, start, i)
            cand[cand_idx] = nums[start]
            permuteFrom(nums, start+1, n, res, cand, cand_idx+1)
            swap(nums, start, i)
        }
    }
}
func permuteUnique(nums []int) [][]int {
    var res [][]int
    cand := make([]int, len(nums))
    permuteFrom(nums, 0, len(nums), &res, cand, 0)
    return res
}
