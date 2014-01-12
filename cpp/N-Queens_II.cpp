class Solution {
public:
    int count;
    int totalNQueens(int n) {
        count = 0;
        vector<bool> col(n, false);
        vector<bool> leftD(2*n-1, false);
        vector<bool> rightD(2*n-1, false);
        solve(n, 0, col, leftD, rightD);
        return count;
    }
    void solve(int n, int rowNo, vector<bool> &col, vector<bool> &leftD, vector<bool> &rightD){
        for (int i = 0; i < n; i ++) {
            if (!col[i] && !leftD[rowNo+i] && !rightD[rowNo-i+(n-1)]) {
                if (rowNo == n-1) {
                    count += 1;
                    return;
                }
                else {
                    col[i] = true;
                    leftD[rowNo+i] = true;
                    rightD[rowNo-i+(n-1)] = true;
                    solve(n, rowNo+1, col, leftD, rightD);
                    col[i] = false;
                    leftD[rowNo+i] = false;
                    rightD[rowNo-i+(n-1)] = false;
                }
            }
        }
    }
};
