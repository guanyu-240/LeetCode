func findMaxLength(nums []int) int {
    sum_idx := make(map[int]int)
    sum,max_size := 0,0
    sum_idx[0] = -1
    for i := 0; i < len(nums); i ++ {
        if nums[i] == 0 {
            sum --
        } else {
            sum ++
        }
        idx,exists := sum_idx[sum]
        if exists{
            if max_size < i-idx {
                max_size = i-idx
            }
        } else {
            sum_idx[sum] = i
        }
    }
    return max_size
}
