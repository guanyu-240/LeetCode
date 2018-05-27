object Solution {
    def letterCasePermutation(S: String): List[String] = {
        def availableChars(c: Char) = {
            if (c >= '0' && c <= '9') List[Char](c)
            else List[Char](Character.toLowerCase(c), Character.toUpperCase(c))
        }
        
        def permutationFrom(S: String, start: Int): List[String] = {
            if (start == S.length()) List[String]("")
            else{
                for (p <- permutationFrom(S, start+1);
                        c <- availableChars(S.charAt(start))) yield c+p
            }
        }
        
        permutationFrom(S, 0)
    }
}
