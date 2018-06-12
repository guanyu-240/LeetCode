func subarraySum(nums []int, k int) int {
    sum_cnt := make(map[int]int)
    subarray_cnt := 0
    sum := 0
    for _,x := range nums {
        sum += x
        if sum == k {
            subarray_cnt ++;
        }
        
        cnt, exists := sum_cnt[sum - k]
        if exists {
            subarray_cnt += cnt
        }

        sum_cnt[sum] ++
    }
    
    return subarray_cnt
}
