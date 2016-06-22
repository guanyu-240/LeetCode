func hIndex(citations []int) int {
    n := len(citations)
    count_papers := make([]int, n+1)
    for i := range citations {
        if citations[i] > n {
            count_papers[n] ++
        } else {
            count_papers[citations[i]] ++
        }
    }
    if count_papers[n] >= n { return n }
    for i := n-1; i >= 0; i-- {
        count_papers[i] += count_papers[i+1]
        if (count_papers[i] >= i) { return i }
    }
    return 0
}
