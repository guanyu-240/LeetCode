func summaryRanges(nums []int) []string {
    ret := []string{}
    n := len(nums)
    start,end := 0,0
    for end < n {
        if end == n-1 || nums[end+1] - nums[end] != 1 { 
            if start == end {
                ret = append(ret, strconv.Itoa(nums[end]))
            } else {
                ret = append(ret, fmt.Sprintf("%d->%d", nums[start], nums[end]))
            }
            start = end+1
        }
        end ++
    }
    return ret
}
