object Solution {
    def flipAndInvertImage(A: Array[Array[Int]]): Array[Array[Int]] = {     
        for (row <- A) yield {
    		for (j <- row.length - 1 to 0 by -1) yield 1 - row(j)
    	}.toArray
    }
}
