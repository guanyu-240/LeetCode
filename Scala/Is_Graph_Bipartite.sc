object Solution {
    def isBipartite(graph: Array[Array[Int]]): Boolean = {
        var nodes = Array.fill[Int](graph.length)(-1)
        def dfs(start: Int): Boolean = {
            var res = true
            for (adj <- graph(start)) {
                if (nodes(adj) == -1) {
                    nodes(adj) = 1 - nodes(start)
                    res &= dfs(adj)
                } else {
                    if (nodes(adj) != 1 - nodes(start)) {
                        return false
                    }
                }
            }
            
            res
        }
        
        var isBiPartite = true
        for (x <- 0 until graph.length if nodes(x) == -1) {
            nodes(x) = 0
            isBiPartite &= dfs(x)
        }
        
        isBiPartite
    }
}
