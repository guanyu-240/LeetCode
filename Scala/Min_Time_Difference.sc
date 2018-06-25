object Solution {
    def findMinDifference(timePoints: List[String]): Int = {
        var n = 24 * 60
        var timePointsExists = Array.fill[Boolean](n)(false)
        var minTs = n
        for (t <- timePoints; split = t.split(":"); ts = split(0).toInt * 60 + split(1).toInt) {
            if (timePointsExists(ts)) {
                return 0
            }
            
            timePointsExists(ts) = true
            minTs = math.min(minTs, ts)
        }
        
        var prev = minTs
        var minDiff = n
        for (ts <- minTs+1 to minTs+n if timePointsExists(ts%n)) {
            minDiff = math.min(minDiff, ts - prev)
            prev = ts
        }
        
        minDiff
    }
}
