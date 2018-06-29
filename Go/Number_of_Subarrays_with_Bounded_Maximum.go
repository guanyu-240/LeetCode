func numSubarrayBoundedMax(A []int, L int, R int) int {
    res := 0
    cur_subarray_cnt := 0
    cur_subarray_len := 0
    for _, x := range A {
        if x > R {
            cur_subarray_cnt = 0
            cur_subarray_len = 0
        } else {
            cur_subarray_len ++
            if (x >= L) {
                cur_subarray_cnt = cur_subarray_len
            }
        }
        
        res += cur_subarray_cnt
    }
    
    return res
}
