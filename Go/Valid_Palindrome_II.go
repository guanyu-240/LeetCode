func validPalindrome(s string) bool {
    start, end := 0, len(s)-1
    attempt_remain := 2
    next_try_start, next_try_end := -1, -1
    for start < end {
        if s[start] == s[end] {
            start ++
            end --
        } else {
            if attempt_remain == 2 {
                next_try_start = start
                next_try_end = end - 1
                start ++
            } else if attempt_remain == 1 {
                start = next_try_start
                end = next_try_end
            } else {
                return false
            }
            attempt_remain --
        }
    }
    
    return true
}
