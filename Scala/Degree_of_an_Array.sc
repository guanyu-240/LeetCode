object Solution {
    def findShortestSubArray(nums: Array[Int]): Int = {
        var posMap = scala.collection.mutable.HashMap[Int, Array[Int]]()
        var maxCnt = 0
        var subArrayLen = nums.length
        
        for (i <- 0 until nums.length) {
            var posTuple = posMap.getOrElseUpdate(nums(i), Array[Int](i, i, 0))
            posTuple(1) = i
            posTuple(2) += 1
            
            if (posTuple(2) > maxCnt) {
                maxCnt = posTuple(2)
                subArrayLen = posTuple(1) - posTuple(0) + 1
            }
            
            if (posTuple(2) == maxCnt) {
                subArrayLen = math.min(subArrayLen, posTuple(1) - posTuple(0) + 1)
            }
        }
        
        subArrayLen
    }
}
