object Solution {
    def maxDistToClosest(seats: Array[Int]): Int = {
        var space = 0
        var dist = 0
        var maxDist = 0
        for (i <- 0 until seats.length) {
            if (seats(i) == 0) {
                space += 1
                if (i == seats.length - 1) {
                    maxDist = math.max(maxDist, space)
                }
            } else {
                if (i > 0 && seats(i-1) == 0) {
                    dist = if (space == i) space else (space + 1) / 2
                    maxDist = math.max(maxDist, dist)
                }
                space = 0
            }
        }
        
        maxDist
    }
}
