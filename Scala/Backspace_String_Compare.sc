object Solution {
    def backspaceCompare(S: String, T: String): Boolean = {
        var i1 = S.length() - 1
        var i2 = T.length() - 1
        var cntBs1 = 0
        var cntBs2 = 0
        while (i1 >= 0 || i2 >= 0) {
            while (i1 >= 0 && (S.charAt(i1) == '#' || cntBs1 > 0)) {
                cntBs1 += (if (S.charAt(i1) == '#') 1 else -1)
                i1 -= 1
            }
            
            while (i2 >= 0 && (T.charAt(i2) == '#' || cntBs2 > 0)) {
                cntBs2 += (if (T.charAt(i2) == '#') 1 else -1)
                i2 -= 1
            }
            
            if (i1 >= 0 && i2 >= 0 && S.charAt(i1) == T.charAt(i2)) {
                i1 -= 1
                i2 -= 1
            } else {
                if (i1 < 0 && i2 < 0) {
                    return true
                } else {
                    return false
                }
            }
        }
        
        return true
    }
}
