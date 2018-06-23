class NumMatrix(_matrix: Array[Array[Int]]) {
    var matrixSum = {
        if (_matrix.length > 0) {
            for (i <- 0 until _matrix.length; j <- 1 until _matrix(i).length) {
                _matrix(i)(j) += _matrix(i)(j-1)
            }
            
            for (i <- 1 until _matrix.length; j <- 0 until _matrix(i).length) {
                _matrix(i)(j) += _matrix(i-1)(j)
            }
        }
        _matrix
    }
    
    def sumRegion(row1: Int, col1: Int, row2: Int, col2: Int): Int = {       
        matrixSum(row2)(col2) + {if (row1 > 0 & col1 > 0) matrixSum(row1-1)(col1-1) else 0} -
            {if (col1 > 0) matrixSum(row2)(col1-1) else 0} -
            {if (row1 > 0) matrixSum(row1-1)(col2) else 0}
    }

}
/**
 * Your NumMatrix object will be instantiated and called as such:
 * var obj = new NumMatrix(matrix)
 * var param_1 = obj.sumRegion(row1,col1,row2,col2)
 */
