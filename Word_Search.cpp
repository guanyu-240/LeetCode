class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word == "") return true;
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        if (n == 0) return false;
        vector<vector<bool> > visited(m, vector<bool>(n));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = true;
                    if (search(board, visited, word, 1, i, j, m, n)){
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, vector<vector<bool> > &visited, string word, int index, int i, int j, int m, int n){
        if (index == word.length()) return true;
        if (i - 1 >= 0 && board[i-1][j] == word[index] && !visited[i-1][j]){
            visited[i-1][j] = true;
            if (search(board, visited, word, index+1, i-1, j, m, n)) {
                return true;
            }
            else visited[i-1][j] = false;
        }
        if (i + 1 < m && board[i+1][j] == word[index] && !visited[i+1][j]){
            visited[i+1][j] = true;
            if (search(board, visited, word, index+1, i+1, j, m, n)) {
                return true;
            }
            else visited[i+1][j] = false;
        }
        if (j - 1 >= 0 && board[i][j-1] == word[index] && !visited[i][j-1]){
            visited[i][j-1] = true;
            if (search(board, visited, word, index+1, i, j-1, m, n)) {
                return true;
            }
            else visited[i][j-1] = false;
        }
        if (j + 1 < n && board[i][j+1] == word[index] && !visited[i][j+1]){
            visited[i][j+1] = true;
            if (search(board, visited, word, index+1, i, j+1, m, n)) {
                return true;
            }
            else visited[i][j+1] = false;
        }
        return false;
    }
    
};
