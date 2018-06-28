import scala.collection.mutable._
object Solution {
    def findCheapestPrice(n: Int, flights: Array[Array[Int]], src: Int, dst: Int, K: Int): Int = {
        var graph = Array.fill[ListBuffer[Array[Int]]](n)(ListBuffer[Array[Int]]())
        var dp = Array.fill[Array[Int]](n)(Array.fill[Int](K+1)(-2))
        
        for (f <- flights) {
            graph(f(0)) += Array[Int](f(1), f(2))            
        }
        
        def dfs(start: Int, depth: Int): Int = {
            var res = -1
            if (depth <= K) {
                for (v <- graph(start)) {
                    if (v(0) == dst) {
                        if (res == -1 || v(1) < res) {
                            res = v(1)
                        }
                    } else {                    
                        if (depth < K) {
                            var tmpRes = if (dp(v(0))(depth + 1) != -2) dp(v(0))(depth + 1) else dfs(v(0), depth + 1)
                            if (tmpRes != -1) {
                                tmpRes += v(1)
                                if (res == -1 || res > tmpRes) {
                                    res = tmpRes
                                }
                            }
                        }
                    }
                }
                dp(start)(depth) = res
            }
            
            res
        }
        
        dfs(src, 0)
    }
}
