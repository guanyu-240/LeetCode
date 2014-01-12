class Solution {
public:
    int count;
    bool rows[9][9];
    bool cols[9][9];
    bool blks[9][9];
    void solveSudoku(vector<vector<char> > &board) {
        count = 0;
        int n = 0;
        // initialize
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                rows[i][j] = cols[i][j] = blks[i][j] = false;
            }
        }
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    count ++;
                    n = board[i][j] - '0';
                    rows[i][n-1] = cols[j][n-1] = blks[(i/3)*3+j/3][n-1] = true;
                }
            }
        }
        solve(board);
    }
    
    bool solve(vector<vector<char>> &board) {
        if (count == 81) return true;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (int n = 1; n <= 9; n ++) {
                        if (!rows[i][n-1] && !cols[j][n-1] && !blks[(i/3)*3+j/3][n-1]) {
                            board[i][j] = n + '0';
                            rows[i][n-1] = cols[j][n-1] = blks[(i/3)*3+j/3][n-1] = true;
                            count ++;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                            rows[i][n-1] = cols[j][n-1] = blks[(i/3)*3+j/3][n-1] = false;
                            count --;
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }
};
