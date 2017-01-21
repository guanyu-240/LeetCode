func validUtf8(data []int) bool {
    if len(data) == 0 {
        return false
    }
    x,mask := 0,1 << 7
    count := 0
    for i := 0; i < len(data); i ++ {
        x = data[i]
        if count == 0 {
            for x&mask == mask {
                x <<= 1
                count ++
            }
            if count > 0 {
                count --
                if count == 0 {
                    return false
                }
            }
        } else {
            if x & mask == mask && (x<<1) & mask == 0 {
                count --;
            } else {
                return false
            }
        }
    }
    return count == 0
}
