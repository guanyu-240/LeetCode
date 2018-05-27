func dominantIndex(nums []int) int {
    largest := 0
    largest_idx := -1
    second_largest := 0
    for i := 0; i < len(nums); i++ {
        if nums[i] > largest {
            second_largest = largest
            largest = nums[i]
            largest_idx = i
        } else {
            if nums[i] >= second_largest {
                second_largest = nums[i]
            }
        }
    }
    
    if second_largest * 2 <= largest {
        return largest_idx
    } else {
        return -1
    }
}
