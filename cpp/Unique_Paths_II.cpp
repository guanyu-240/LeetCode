class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
                
        obstacleGrid[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        int x,y;
        if (m * n > 1){
            for (int i = 1; i < n + m - 1; i ++){
                y = min(i, n - 1);
                x = i - y;
                while (x < m && y >= 0){
                    if (obstacleGrid[x][y] != 1){
                        obstacleGrid[x][y] = 0;
                        obstacleGrid[x][y] += ((x == 0) ? 0 : obstacleGrid[x - 1][y]);
                        obstacleGrid[x][y] += ((y == 0) ? 0 : obstacleGrid[x][y - 1]);
                    }
                    else{
                        obstacleGrid[x][y] = 0;
                    }
                    y --;
                    x ++;
                }
            }
        }
        return obstacleGrid[m - 1][n - 1];
    }
};
