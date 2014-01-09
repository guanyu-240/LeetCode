class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool rows[9][9] = { false }; // rows[m][n]: if the row m ahready has number n
        bool cols[9][9] = { false }; // cols[m][n]: if the col m already has number n
        bool blks[9][9] = { false }; // blks[m][n]: if the blk m already has number n

        for (int i = 0; i < 9; i ++){
            for (int j = 0; j < 9; j ++){
                if (board[i][j] == '.') {
                    continue;
                }
                int n = board[i][j] - '1';
                if (rows[i][n] || cols[j][n] || blks[(i/3)*3 + j/3][n]){
                    return false;
                }
                rows[i][n] = cols[j][n] = blks[(i/3)*3 + j/3][n] = true;
            }
        }
        return true;
    }
};
