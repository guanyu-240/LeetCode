object Solution {
    def anagramMappings(A: Array[Int], B: Array[Int]): Array[Int] = {
        val BMap = B.zipWithIndex.toMap
        for (x <- A) yield {
        	if (BMap.keySet.contains(x)) BMap(x)
        	else -1
        }
    }
}
