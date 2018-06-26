object Solution {
    def judgeSquareSum(c: Int): Boolean = {
        for (x <- 0 to math.sqrt(c).toInt) {
            if (math.sqrt(c - x*x).toInt == math.sqrt(c-x*x)) {
                return true
            }
        }
        
        false
    }
}
