class Solution(object):
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        start,digits = 1,1
        while n - 9*start*digits > 0:
            n -= 9*start*digits
            start *= 10
            digits += 1
        n -= 1
        return int(str(start+n/digits)[n%digits])
