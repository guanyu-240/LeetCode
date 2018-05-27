object Solution {
    def findLengthOfLCIS(nums: Array[Int]): Int = {
        var maxLen = 0
        var seqLen = 0
        for (i <- 0 until nums.length) {
            if (i == 0 || nums(i) > nums(i-1)) {
                seqLen += 1
            } else {
                seqLen = 1
            }
            maxLen = math.max(seqLen, maxLen)
        }
        maxLen
    }
}
