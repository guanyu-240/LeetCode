class Solution:
    # @return an integer
    def totalNQueens(self, n):
        assert n > 0
        cols = n*[False]
        leftD = (2*n-1)*[False]
        rightD = (2*n-1)*[False]
        ret = 0
        selection = n*[-1]
        row = 0
        while row >= 0:
            selectedCol = selection[row]
            if selectedCol >= 0:
                cols[selectedCol] = False
                leftD[row+selectedCol] = False
                rightD[row-selectedCol+n-1] = False
            selected = False
            for i in range(selection[row]+1, n):
                if (not cols[i]) and (not leftD[row+i]) and (not rightD[row-i+n-1]):
                    if row == n - 1:
                        ret = ret + 1
                    else:
                        selected = True
                        cols[i] = True
                        leftD[row+i] = True
                        rightD[row-i+n-1] = True
                        selection[row] = i
                        break
            if selected: row = row + 1
            else:
                selection[row] = -1
                row = row - 1
        return ret
