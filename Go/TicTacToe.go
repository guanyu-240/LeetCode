type TicTacToe struct {
    rows [2][]int
    cols [2][]int
    diagonal [2]int
    anti_diagonal [2]int
    n int
}


/** Initialize your data structure here. */
func Constructor(n int) TicTacToe {
    return TicTacToe {
        rows : [2][]int{make([]int, n), make([]int, n)},
        cols : [2][]int{make([]int, n), make([]int, n)},
        diagonal : [2]int{0, 0},
        anti_diagonal : [2]int{0, 0},
        n : n,
    }
}


/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
func (this *TicTacToe) Move(row int, col int, player int) int {
    this.rows[player-1][row] ++;
    this.cols[player-1][col] ++
    if row == col {
        this.diagonal[player-1] ++
    }
    if row+col+1 == this.n {
        this.anti_diagonal[player-1] ++
    }
    if this.rows[player-1][row] == this.n ||
            this.cols[player-1][col] == this.n ||
            this.diagonal[player-1] == this.n ||
            this.anti_diagonal[player-1] == this.n {
        return player    
    } else {
        return 0
    }
}


/**
 * Your TicTacToe object will be instantiated and called as such:
 * obj := Constructor(n);
 * param_1 := obj.Move(row,col,player);
 */
