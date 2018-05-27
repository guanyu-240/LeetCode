object Solution {
    def allPathsSourceTarget(graph: Array[Array[Int]]): List[List[Int]] = {
        def allPathsToTarget(src: Int): List[List[Int]] = {
            if (src == graph.length - 1) List(List(src))
            else {
                for (adj <- graph(src).toList;
                				path <- allPathsToTarget(adj)) yield src::path
            }
        }
        allPathsToTarget(0)
    }
}
