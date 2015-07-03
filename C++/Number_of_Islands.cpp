class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;
        int ret = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int x = 0; x < m; x ++) {
            for (int y = 0; y < n; y ++) {
                ret += dfs(grid, visited, x, y, m, n);
            }
        }
        return ret;
    }
    
    int dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited,
            int x, int y, int m, int n){
        if (x < 0 || x >= m || y < 0 || y >= n) return 0;
        if (grid[x][y] == '0' || visited[x][y]) return 0;
        visited[x][y] = true;
        dfs(grid, visited, x, y+1, m, n);
        dfs(grid, visited, x, y-1, m, n);
        dfs(grid, visited, x+1, y, m, n);
        dfs(grid, visited, x-1, y, m, n);
        return 1;
    }
};
