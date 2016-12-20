class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        ret = 0
        diff = x^y
        while diff > 0:
            ret += (diff & 1)
            diff >>= 1
        return ret
