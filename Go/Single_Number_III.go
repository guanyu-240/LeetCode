func singleNumber(nums []int) []int {
    ret := []int{0, 0}
    xor := 0
    for i := range(nums) {
        xor ^= nums[i]
    }
    mask := 1
    // find a bit which only one of them has, let this number be a
    for mask & xor == 0 {
        mask <<= 1
    }
    // find all numbers share that bit with a, xor all of them
    // then get a
    for i := range(nums) {
        if mask & nums[i] == mask {
            ret[0] ^= nums[i]
        }
    }
    ret[1] = ret[0] ^ xor
    return ret
}
