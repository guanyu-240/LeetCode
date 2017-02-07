func spiralOrder(matrix [][]int) []int {
    m := len(matrix)
    if m == 0 {
        return make([]int, 0)
    }
    n := len(matrix[0])
    if n == 0 {
        return make([]int, 0)
    }
    spiral := make([]int, m*n)
    up,down,left,right := 0, m-1, 0, n-1
    idx := 0
    for up <= down && left <= right {
        for i := left; i <= right; i ++ {
            spiral[idx] = matrix[up][i]
            idx ++
        }
        for i := up+1; i <= down; i ++ {
            spiral[idx] = matrix[i][right]
            idx ++
        }
        if left == right || up == down {
            break
        }
        for i := right-1; i >= left; i -- {
            spiral[idx] = matrix[down][i]
            idx ++
        }
        for i := down-1; i > up; i -- {
            spiral[idx] = matrix[i][left]
            idx ++
        }
        left ++;
        right --;
        up ++;
        down --;
    }
    return spiral
}
