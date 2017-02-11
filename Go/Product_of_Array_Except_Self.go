func productExceptSelf(nums []int) []int {
    left,right := 1,1
    n := len(nums)
    products := make([]int, n)
    if n%2 != 0 {
        products[n/2] = 1
    }
    for i := 0; i < n; i ++ {
        if i < n/2 {
            products[i] = left
            products[n-i-1] = right
        } else {
            products[i] *= left
            products[n-i-1] *= right
        }
        left *= nums[i]
        right *= nums[n-i-1]
    }
    return products
}
