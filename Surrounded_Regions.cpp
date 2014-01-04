class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;
        vector<int> bfsX, bfsY;
        bfsX.clear(); bfsY.clear();
        for (int i = 0; i < m; i ++) {
            if (board[i][0] == 'O') {
                bfsX.push_back(i); bfsY.push_back(0);
            }
            if (board[i][n-1] == 'O') {
                bfsX.push_back(i); bfsY.push_back(n-1);
            }
        }
        for (int j = 0; j < n; j ++) {
            if (board[0][j] == 'O') {
                bfsX.push_back(0); bfsY.push_back(j);
            }
            if (board[m-1][j] == 'O') {
                bfsX.push_back(m-1); bfsY.push_back(j);
            }
        }
        bfs(board, bfsX, bfsY, m, n);
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'M') board[i][j] = 'O';
            }
        }
    }
    void bfs(vector<vector<char>> &board, vector<int> &bfsX, vector<int> &bfsY, int m, int n) {
        int i,j;
        int k = 0;
        while (k < bfsX.size()) {
            i = bfsX[k]; j = bfsY[k];
            board[i][j] = 'M';
            if (i+1 < m && board[i+1][j] == 'O'){
                bfsX.push_back(i+1); bfsY.push_back(j);
            }
            if (i-1 > 0 && board[i-1][j] == 'O'){
                bfsX.push_back(i-1); bfsY.push_back(j);
            }
            if (j+1 < n && board[i][j+1] == 'O'){
                bfsX.push_back(i); bfsY.push_back(j+1);
            }
            if (j-1 > 0 && board[i][j-1] == 'O'){
                bfsX.push_back(i); bfsY.push_back(j-1);
            }
            k++;
        }
    }
};
