object Solution {
    def largestTriangleArea(points: Array[Array[Int]]): Double = {
        def area(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int): Double = {
            0.5 * math.abs(x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x1 * y3 - x3 * y2)
        }
        val n = points.length
        var maxArea = 0.0
        for (i <- 0 to n-3;
                j <- i+1 to n-2;
                k <- j+1 to n-1) {
            maxArea = math.max(maxArea, 
                          area(points(i)(0),
                                points(i)(1),
                                points(j)(0),
                                points(j)(1),
                                points(k)(0),
                                points(k)(1)))
        }
        
        maxArea
    }
}
