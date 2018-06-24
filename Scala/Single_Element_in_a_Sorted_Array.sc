object Solution {
    def singleNonDuplicate(nums: Array[Int]): Int = {
        /*
         * left   -> nums[2i] == nums[2i+1]
         * right  -> nums[2i] == nums[2i-1]
         * target -> nums[2i+1] != nums[2i] != nums[2i+1]
         */
        var left = 0
        var right = nums.length / 2
        var x = 0
        while (left <= right) {
            x = (left + right) / 2
            if (x == nums.length / 2 || (nums(2*x) != nums(2*x+1) && (x == 0 || (nums(2*x) != nums(2*x-1))))) {
                return nums(2*x)
            } else if (nums(2*x) == nums(2*x+1)) {
                left = x + 1
            } else {
                right = x - 1
            }
        }
        
        return -1
    }
}
