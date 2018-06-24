object Solution {
    def scoreOfParentheses(S: String): Int = {
        // Only need to consider closing "()" pair and it's level
        var leftCnt = 0
        var score = 0
        var prev : Char = 0
        
        for (p <- S) {
            if (p == '(') {
                leftCnt += 1
            } else {
                leftCnt -= 1
                if (prev == '(') {
                    score += math.pow(2, leftCnt).toInt
                }
            }
                
            prev = p
        }
                    
        score
    }
}
