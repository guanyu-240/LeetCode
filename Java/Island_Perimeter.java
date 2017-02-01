public class Solution {
    private int dfs(int[][] grid, int m, int n, int x, int y) {
        if (grid[x][y] == -1) return 0;
        int ret = 0;
        grid[x][y] = -1;
        if (x == 0 || grid[x-1][y] == 0) ret ++;
        else ret += dfs(grid, m, n, x-1, y);
        if (x == m-1 || grid[x+1][y] == 0) ret ++;
        else ret += dfs(grid, m, n, x+1, y);
        if (y == 0 || grid[x][y-1] == 0) ret ++;
        else ret += dfs(grid, m, n, x, y-1);
        if (y == n-1 || grid[x][y+1] == 0) ret ++;
        else ret += dfs(grid, m, n, x, y+1);
        return ret;
    }
    public int islandPerimeter(int[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        if (n == 0) return 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    return dfs(grid, m, n, i, j);
                }
            }
        }
        return 0;
    }
}
