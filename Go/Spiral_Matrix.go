func spiralOrder(matrix [][]int) []int {
    var spiral []int
    m := len(matrix)
    if m == 0 {
        return spiral
    }
    n := len(matrix[0])
    if n == 0 {
        return spiral
    }
    up,down,left,right := 0, m-1, 0, n-1
    for up <= down && left <= right {
        for i := left; i <= right; i ++ {
            spiral = append(spiral, matrix[up][i])
        }
        for i := up+1; i <= down; i ++ {
            spiral = append(spiral, matrix[i][right])
        }
        if left == right || up == down {
            break
        }
        for i := right-1; i >= left; i -- {
            spiral = append(spiral, matrix[down][i])
        }
        for i := down-1; i > up; i -- {
            spiral = append(spiral, matrix[i][left])
        }
        left ++;
        right --;
        up ++;
        down --;
    }
    return spiral
}
