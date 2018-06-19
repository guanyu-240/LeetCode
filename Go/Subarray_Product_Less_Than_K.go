func numSubarrayProductLessThanK(nums []int, k int) int {
    if (len(nums) == 0) {
        return 0
    }
    
    cnt     := 0
    start   := 0
    end     := 0
    product := nums[0]
    for start < len(nums){
        if product < k && end < len(nums) {
            end ++;
            if end != len(nums) {
                product *= nums[end]
            }
        } else {
            cnt += end - start // Any subarray starting with 'start' and ending before 'end' satisfies
            product /= nums[start]
            start ++
            if end < start {
                end = start
            }
        }
    }

    return cnt
}
