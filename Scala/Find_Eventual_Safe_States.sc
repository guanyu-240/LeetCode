object Solution {
    def eventualSafeNodes(graph: Array[Array[Int]]): List[Int] = {
        /*
         * State:
         * 0  : unvisited
         * 1  : visited in current search
         * -1 : in a loop
         * 2  : not in a loop
         */
        var state = Array.fill[Int](graph.length)(0)
        
        def dfs(start: Int): Boolean = {
            var res = true
            res = state(start) match {
                case 0 => state(start) = 1; graph(start).foreach(a => res &= dfs(a)); res
                case 1 => false
                case -1 => false
                case default => true
            }
            
            state(start) = if (res) 2 else -1
            res
        }
        
        for (i <- 0 until graph.length if state(i) == 0) {
            dfs(i)
        }
        
        (for {i <- 0 until graph.length if state(i) == 2} yield i).toList
        
    }
}
