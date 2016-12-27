class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        """
        :type n: int
        :rtype: int
        Unique Numbers with k digits: 9*C(9, k-1)
        ret = 1+9*(A(9, 0) + A(9, 1) + ... + A(9, n-1))
        n <= 10
        """
        n,i = min(10, n),1
        ret = 1
        p = 1
        while i <= n:
            ret += 9*p
            p *= (9-i+1)
            i += 1
        return ret
