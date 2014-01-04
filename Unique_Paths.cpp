class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (m * n <= 1){
            return m * n;
        }
        
        int paths[m][n];
        paths[0][0] = 1;
        int x,y;
        for (int i = 1; i < n + m - 1; i ++){
            y = min(i, n - 1);
            x = i - y;
            while (x < m && y >= 0){
                paths[x][y] = 0;
                paths[x][y] += ((x == 0) ? 0 : paths[x - 1][y]);
                paths[x][y] += ((y == 0) ? 0 : paths[x][y - 1]);
                y --;
                x ++;
            }
        }
        return paths[m - 1][n - 1];
    }
};
