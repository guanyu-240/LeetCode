func countBits(num int) []int {
    if (num < 0) { return []int{} }
    ret := make([]int, num+1);
    var lastPO2 int
    for x := 1; x <= num; x++ {
        if (x & (x-1)) == 0 {
            ret[x] = 1
            lastPO2 = x
        } else {
            ret[x] = ret[lastPO2]+ret[x-lastPO2]
        }
    }
    return ret
}
