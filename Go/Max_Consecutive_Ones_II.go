func findMaxConsecutiveOnes(nums []int) int {
    n := len(nums)
    curSeq, prevSeq := 0, 0
    gap := 0
    ret, tmpRet := 0, 0
    for i := 0; i < n; i ++ {
        if nums[i] == 1 {
            curSeq ++
        } else {
            if i == 0 || nums[i-1] == 0 {
                gap ++
            } else {
                gap = 1
            }
            prevSeq = curSeq
            curSeq = 0
        }
        
        if gap <= 1 {
            tmpRet = curSeq+prevSeq+gap
        } else {
            tmpRet = curSeq+1
        }
        
        if tmpRet > ret {
            ret = tmpRet
        }
    }
    return ret
}
