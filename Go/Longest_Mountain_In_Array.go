func longestMountain(A []int) int {
    start,end := -1,-1
    largest_mountain := 0
    for i,h := range A {
        if i == 0 { continue }
        if h > A[i-1] {
            if start <= end {
                start = i-1
                end = -1
            }
        } else if h == A[i-1] {
            start = -1
            end = -1
        } else {
            if start != -1 {
                end = i
            }
        }
        if end != -1 && end - start + 1 > largest_mountain {
            largest_mountain = end - start + 1
        }
    }
    
    return largest_mountain
}
