func solve(nums []int, idx int, arr_sum int, S int) int {
    if idx >= len(nums) {
        if S == 0 {
            return 1
        } else {
            return 0
        }
    }
    if arr_sum < S || -arr_sum > S {
        return 0
    }
    if nums[idx] == 0 {
        return 2*solve(nums, idx+1, arr_sum, S)
    }
    return solve(nums, idx+1, arr_sum-nums[idx], S-nums[idx]) +
            solve(nums, idx+1, arr_sum-nums[idx], S+nums[idx])
}

func findTargetSumWays(nums []int, S int) int {
    arr_sum := 0
    for i := 0; i < len(nums); i ++ {
        arr_sum += nums[i]
    }
    return solve(nums, 0, arr_sum, S)
}
