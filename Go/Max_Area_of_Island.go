func maxOfTwoInt(x int, y int) int {
    if x > y {
        return x
    } else {
        return y
    }
}

func dfs(x int, y int, grid [][]int) int {
    if x < 0 || x >= len(grid) || y < 0 || y >= len(grid[0]) {
        return 0
    }
    
    if grid[x][y] == 0 {
        return 0
    }
    
    grid[x][y] = 0
    return 1 + dfs(x-1, y, grid) +
                dfs(x, y-1, grid) +
                dfs(x+1, y, grid) +
                dfs(x, y+1, grid)
}

func maxAreaOfIsland(grid [][]int) int {
    if len(grid) == 0 {
        return 0
    }
    
    if len(grid[0]) == 0 {
        return 0
    }
    
    gridCopy := grid
    maxArea := 0
    for x := range(gridCopy) {
        for y := range(gridCopy[0]) {
            if grid[x][y] == 1 {
                maxArea = maxOfTwoInt(maxArea, dfs(x, y, gridCopy))
            }
        }
    }
    
    return maxArea
}
