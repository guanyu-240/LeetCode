func getModifiedArray(length int, updates [][]int) []int {
    incs := make([]int, length)
    start,end,val := 0, 0, 0
    for i := range updates {
        start = updates[i][0]
        end = updates[i][1]
        val = updates[i][2]
        incs[start] += val
        if end < length-1 {
            incs[end+1] -= val
        }
    }
    for i := 1; i < length; i++ {
        incs[i] += incs[i-1]
    }
    return incs
}
