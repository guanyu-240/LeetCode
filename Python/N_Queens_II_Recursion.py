class Solution:
    # @return an integer
    def totalNQueens(self, n):
        assert n > 0
        cols = n*[False]
        leftD = (2*n-1)*[False]
        rightD = (2*n-1)*[False]
        return self.solve(n, 0, cols, leftD, rightD)
    def solve(self, n, row, cols, leftD, rightD):
        ret = 0
        for i in range(n):
            if (not cols[i]) and (not leftD[row+i]) and (not rightD[row-i+n-1]):
                if row == n-1: 
                    return 1
                else:
                    cols[i] = True
                    leftD[row+i] = True
                    rightD[row-i+n-1] = True
                    ret = ret + self.solve(n, row+1, cols, leftD, rightD)
                    cols[i] = False
                    leftD[row+i] = False
                    rightD[row-i+n-1] = False
        return ret
