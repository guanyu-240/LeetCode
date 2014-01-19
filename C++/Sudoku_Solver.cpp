class Solution {
public:
    int count;
    void solveSudoku(vector<vector<char> > &board) {
        bool rows[9][9] = { false }; // rows[m][n]: if the row m ahready has number n
        bool cols[9][9] = { false }; // cols[m][n]: if the col m already has number n
        bool blks[9][9] = { false }; // cols[m][n]: if the col m already has number n
        int n;
        count = 0;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    count ++;
                    n = board[i][j] - '0';
                    rows[i][n-1] = cols[j][n-1] = blks[(i/3)*3+j/3][n-1] = true;
                }
            }
        }
        solve(board, rows, cols, blks);
    }
    
    bool solve(vector<vector<char>> &board, bool (&rows)[9][9], bool (&cols)[9][9], bool (&blks)[9][9]) {
        if (count == 81) return true;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] == '.') {
                    for (int n = 1; n <= 9; n ++) {
                        if (!rows[i][n-1] && !cols[j][n-1] && !blks[(i/3)*3+j/3][n-1]) {
                            board[i][j] = n + '0';
                            rows[i][n-1] = cols[j][n-1] = blks[(i/3)*3+j/3][n-1] = true;
                            count ++;
                            if (solve(board, rows, cols, blks)) return true;
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
