object Solution {
    def maxCount(m: Int, n: Int, ops: Array[Array[Int]]): Int = {
        var rowMin = m
        var colMin = n        
        for (op <- ops) {
            rowMin = math.min(rowMin, op(0))
            colMin = math.min(colMin, op(1))
        }
        
        rowMin * colMin
    }
}
