class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        Keep the smallest elements of each row in the heap
        complexity: k*log n
        """
        n = len(matrix)
        h = []
        min_e = None
        for i in range(n): heapq.heappush(h, (matrix[i][0], (i, 0)))
        for i in range(k):
            min_e = heapq.heappop(h)
            r,c = min_e[1][0], min_e[1][1]
            if c < n-1: heapq.heappush(h, (matrix[r][c+1], (r, c+1)))
        return min_e[0]
