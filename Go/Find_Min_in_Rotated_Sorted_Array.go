func findMin(nums []int) int {
    if len(nums) == 0 {
        return 0
    }
    left, right := 0, len(nums)-1
    var mid int
    for left <= right {
        if left == right {
            return nums[left]
        } else {
            mid = (left+right)/2
            if nums[left] <= nums[mid] { // left half already sorted
                if nums[left] < nums[right] { // all sorted
                    return nums[left]
                } else {
                    left = mid + 1
                }
            } else {
                right = mid
            }
        }
    }
    return 0
}
