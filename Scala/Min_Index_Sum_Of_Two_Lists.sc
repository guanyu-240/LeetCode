object Solution {
    def findRestaurant(list1: Array[String], list2: Array[String]): Array[String] = {
        var indexMap = scala.collection.mutable.HashMap[String, Array[Int]]()
        var indexes : Array[Int] = null
        var minIndexSum = list1.length + list2.length
        
        for (i <- 0 until math.max(list1.length, list2.length)) {
            if (i < list1.length) {
                indexes = indexMap.getOrElseUpdate(list1(i), Array[Int](i, -1))
                indexes(0) = i
                if (indexes(0) != -1 && indexes(1) != -1) {
                    minIndexSum = math.min(minIndexSum, indexes(0) + indexes(1))
                }
            }
            
            if (i < list2.length) {
                indexes = indexMap.getOrElseUpdate(list2(i), Array[Int](-1, i))
                indexes(1) = i
                if (indexes(0) != -1 && indexes(1) != -1) {
                    minIndexSum = math.min(minIndexSum, indexes(0) + indexes(1))
                }
            }
        }
        
        (for {(k,v) <- indexMap if v(0) != -1 && v(1) != -1 && v(0) + v(1) == minIndexSum} yield k).toArray
    }
}
