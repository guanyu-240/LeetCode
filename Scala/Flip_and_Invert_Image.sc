object Solution {
    def flipAndInvertImage(A: Array[Array[Int]]): Array[Array[Int]] = {
    		for (i <- 0 to A.length) {
    			for (j <- 0 to A(i).length/2) {
    				val v = A(i)(j)
    				A(i)(j) = 1 - A(i)(A(i).length-1-j)
    				A(i)(A(i).length-1-j) = 1 - v
    			}
    		}
    		A
    }
}
