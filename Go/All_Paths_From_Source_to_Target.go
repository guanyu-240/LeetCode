func allPathsSourceTarget(graph [][]int) [][]int {
    paths := allPathsToTarget(graph, 0)
    var tmp int
    for _, path := range(paths) {
        for i := 0; i < len(path)/2; i ++ {
            tmp = path[i]
            path[i] = path[len(path)-i-1]
            path[len(path)-i-1] = tmp
        }
    }
    return paths
}

func allPathsToTarget(graph [][]int, src int) [][]int{
    var res [][]int
    if src == len(graph) - 1 {
        res = append(res, []int{src})
    } else {
        for _, adj := range(graph[src]) {
            paths := allPathsToTarget(graph, adj)
            for _, path := range(paths) {
                res = append(res, append(path, src))
            }
        }
    }
    
    return res
}
