object Solution {
    def findErrorNums(nums: Array[Int]): Array[Int] = {
        var sumDiff = 0
        var squareSumDiff = 0
        for (i <- 1 to nums.length) {
            sumDiff += i - nums(i-1)
            squareSumDiff += i * i - nums(i-1) * nums(i-1)
        }
        
        var missing = (squareSumDiff / sumDiff + sumDiff) / 2       
        Array[Int](missing - sumDiff, missing)
    }
}
