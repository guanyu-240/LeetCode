object Solution {
    def checkPossibility(nums: Array[Int]): Boolean = {
        if (nums.length <= 2) {
            return true
        }
        
        var inverseExist = false
        for (i <- 1 until nums.length) {
            if (nums(i) < nums(i-1)) {
                if (inverseExist) {
                    return false
                }
                
                // If nums(i) < nums(i-2), need to increase the current one
                // If the next number does not satisfy, return false directly
                if (i > 1 && i < nums.length - 1 && nums(i) < nums(i-2) && nums(i+1) < nums(i-1)) {
                    return false
                }
                
                inverseExist = true
            }
        }
        
        return true
    }
}
