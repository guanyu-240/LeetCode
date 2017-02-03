public class Solution {
    public int countBattleships(char[][] board) {
        /*
        The 1st component of a battleship should not have
        left neighbor or up neighbor, since the board is
        always valid
        */
        int cnt = 0;
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                if (board[i][j] == 'X' && 
                    (i == 0 || board[i-1][j] == '.') &&
                    (j == 0 || board[i][j-1] == '.'))
                    cnt ++;
            }
        }
        return cnt;
    }
}
