func longestPalindrome(s string) int {
    count := make(map[byte]int)
    ret := 0
    for i := 0; i < len(s); i ++ {
        count[s[i]] ++;
    }
    to_add := 0
    for _,v := range(count) {
        if v % 2 == 0 {
            ret += v
        } else {
            ret += v-1
            to_add = 1
        }
    }
    return ret + to_add
}
