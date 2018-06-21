object Solution {
    def customSortString(S: String, T: String): String = {
        var charCnt = scala.collection.mutable.Map[Char, Int]()
        for (c <- T) {
            charCnt.put(c, 1 + charCnt.getOrElse(c, 0))
        }
        
        var charsInS = for {c <- S; i <- 1 to charCnt.getOrElse(c, 0)} yield c
        var remain = (for {(c, cnt) <- charCnt; i <- 1 to cnt; if !S.contains(c)} yield c).mkString		
		charsInS + remain
    }
}
