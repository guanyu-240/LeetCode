func findDiagonalOrder(matrix [][]int) []int {
    var order []int
    m := len(matrix)
    if m == 0 { return order }
    n := len(matrix[0])
    if n == 0 { return order }
    level_max := m+n-1
    inc,x,y := 1,0,0
    for level := 0; level < level_max; level ++ {
        if level % 2 == 1 {
            inc = 1
            x,y = 0,level
            if level >= n {
                x,y = level-n+1, n-1
            }
        } else {
            inc = -1
            x,y = level, 0
            if level >= m {
                x,y = m-1, level-m+1
            }
        }
        for x >= 0 && x < m && y >= 0 && y < n {
            order = append(order, matrix[x][y])
            x += inc
            y -= inc
        }
    }
    return order
}
