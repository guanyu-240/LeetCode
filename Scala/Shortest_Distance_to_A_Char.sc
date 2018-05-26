object Solution {
    def shortestToChar(S: String, C: Char): Array[Int] = {
        val positions = for (i <- 0 to S.length()-1 if S(i) == C) yield i
        var distances = new Array[Int](S.length())
        if (positions.length == 0) {
            return distances
        }
        var idx = 0
        for (i <- 0 to S.length()-1) {
            if (positions(idx) >= i) {
                distances(i) = positions(idx) - i
            } else {
                if (idx == positions.length - 1 || i - positions(idx) < positions(idx+1) - i) {
                    distances(i) = i - positions(idx)
                } else {
                    idx += 1
                    distances(i) = positions(idx) - i
                }
            }
        }
        
        return distances
    }
}
