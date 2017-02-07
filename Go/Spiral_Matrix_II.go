func generateMatrix(n int) [][]int {
    spiral := make([][]int, n)
    for i := 0; i < n; i ++ {
        spiral[i] = make([]int, n)
    }
    level := 0
    number := 1
    var diff int
    for level < n/2 {
        diff = n-1-2*level
        for i := level; i < n-1-level; i ++ {
            spiral[level][i] = number
            spiral[i][n-1-level] = number + diff
            spiral[n-1-level][n-1-i] = number + 2*diff
            spiral[n-1-i][level] = number + 3*diff
            number ++
        }
        level ++
        number += diff*3
    }
    if n%2 != 0 {
        spiral[n/2][n/2] = number
    }
    return spiral
}
