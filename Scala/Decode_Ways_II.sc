object Solution {
    def numDecodings(s: String): Int = {
        def numDecodingsTwoDigits(d1: Char, d2: Char): Long = {
            if (d1 == '1') {
                if (d2 == '*') 9 else 1
            } else if (d1 == '2') {
                if (d2 == '*') 6 else if (d2 <= '6') 1 else 0
            } else if (d1 == '*') {
                if (d2 == '*') 15 
                else if (d2 >= '0' && d2 <= '6') 2
                else 1
            } else 0
        }
        
        var mod = math.pow(10,9).toInt + 7
        var n = s.length()
        var dp = Array.fill[Long](n+1)(1)
        for (i <- n - 1 to 0 by -1) {
            dp(i) = (if (s.charAt(i) == '*') 9
                        else if (s.charAt(i) != '0') 1
                        else 0) * dp(i+1) % mod
            
            if (i < n - 1) {
                dp(i) += numDecodingsTwoDigits(s.charAt(i), s.charAt(i+1)) * dp(i+2) % mod
            }
            
            dp(i) %= mod
        }
        
        dp(0).toInt
    }       
}
