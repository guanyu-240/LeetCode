object Solution {
    def isIdealPermutation(A: Array[Int]): Boolean = {
        // No global inversion other than local
        // For local inversion A[i] and A[i+1], A[i+1] >= any A[j] where j < i
        if (A.length <= 2) {
            return true
        }
        
        var maxBeforePrev = A(0)
        for (i <- 2 until A.length) {
            if (A(i) < maxBeforePrev) {
                return false
            }
            
            maxBeforePrev = math.max(A(i-1), maxBeforePrev)
        }
        
        return true
    }
}
