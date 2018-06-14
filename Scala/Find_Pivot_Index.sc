object Solution {
    def pivotIndex(nums: Array[Int]): Int = {
        if (nums.length <= 1) {
            return nums.length - 1
        }
        
        var sums = Array.fill[Int](nums.length+2)(0)
        sums(0) = 0
        for (i <- 0 until nums.length) {
            sums(i+1) = sums(i) + nums(i) 
        }
        
        sums(sums.length - 1) = sums(sums.length - 2)
             
        for (i <- 0 until nums.length) {
            if (sums(i+1) == sums(sums.length - 1) - sums(i)) {
                return i
            }
        }
        
        return -1
    }
}
