object Solution {
    def nextGreaterElement(n: Int): Int = {
        var digits = n.toString.toArray
        
        def swap(i: Int, j: Int): Unit = {
            var tmp : Char = 0
            tmp = digits(j)
            digits(j) = digits(i)
            digits(i) = tmp
        }

        for (i <- digits.length - 2 to 0 by -1) {
            if (digits(i) < digits(i+1)) {
                var j = i + 1
                while (j < digits.length && digits(j) > digits(i)) {
                    j += 1
                }
                
                swap(i, j-1)
                
                for (k <- i+1 to (i+digits.length)/2) {
                    println(k)
                    swap(k, digits.length-k+i)
                }
                
                var res = digits.mkString.toLong
                if (res <= Int.MaxValue) {
                    return res.toInt
                } else {
                    return -1
                }
            }
        }
        
        -1
    }
}
