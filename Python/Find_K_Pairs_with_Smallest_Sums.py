class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        h = []
        ret = []
        for x in nums1:
            for y in nums2:
                if len(h) == k:
                    if h[0][0] < -1*(x+y):
                        heapq.heapreplace(h, (-1*(x+y), [x, y]))
                    else: break
                else:
                    heapq.heappush(h, (-1*(x+y), [x, y]))
        while len(h) > 0:
            ret.append(heapq.heappop(h)[1])
            
        return ret
