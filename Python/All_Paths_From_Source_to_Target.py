class Solution(object):
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        paths = self.pathsToTarget(graph, 0)
        for path in paths:
            path.reverse()
        return paths
        
    def pathsToTarget(self, graph, src):
        res = []
        if src == len(graph) - 1:
            res.append([src])
        elif len(graph[src]) > 0:
            for adj in graph[src]:
                paths = self.pathsToTarget(graph, adj)
                for path in paths:
                    path.append(src)
                    res.append(path)
        return res
