func sortTransformedArray(nums []int, a int, b int, c int) []int {
    n := len(nums)
    ret := make([]int, n)
    ptr_l,ptr_r := -1,-1
    increase := false
    vertex := 0.0
    if a == 0 {
        ptr_r = 0
        if b >= 0 {
            increase = true
        }
    } else {
        if a > 0 {
            increase = true
        }
        vertex = float64(b)*(-1.0)/(2.0*float64(a))
        for ptr_l < n-1 && float64(nums[ptr_l+1]) < vertex {
            ptr_l ++
        }
        ptr_r = ptr_l+1
    }
    
    ptr_ret,move,cand := 0,1,0
    if !increase {
        ptr_ret,move = n-1,-1
    }
    for ptr_l >= 0 || ptr_r < n {
        if ptr_l < 0 {
            cand = nums[ptr_r]
            ptr_r ++
        } else if ptr_r >= n {
            cand = nums[ptr_l]
            ptr_l --
        } else if vertex - float64(nums[ptr_l]) > float64(nums[ptr_r]) - vertex {
            cand = nums[ptr_r]
            ptr_r ++
        } else {
            cand = nums[ptr_l]
            ptr_l --
        }
        ret[ptr_ret] = a*cand*cand+b*cand+c;
        ptr_ret += move
    }
    return ret
}
