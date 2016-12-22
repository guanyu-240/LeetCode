class Solution(object):
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        n = len(A)
        m = collections.Counter(A[i]+B[j] for i in range(n) for j in range(n))
        ret = sum(m[-C[k]-D[l]] for k in range(n) for l in range(n))
        return ret
