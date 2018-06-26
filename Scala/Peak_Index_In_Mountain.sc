object Solution {
    def peakIndexInMountainArray(A: Array[Int]): Int = {
        for (i <- 1 until A.length - 1) {
            if (A(i) > A(i-1) && A(i) > A(i+1)) {
                return i
            }
        }
        
        -1
    }
}
