class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        low,high = 1,1
        while high*high < num: high <<= 1
        if high*high == num: return True
        low = (high >> 1)
        while low <= high:
            mid = (high+low)/2
            tmp = mid*mid
            if tmp == num: return True
            elif tmp < num: low = mid+1
            else: high = mid-1
        return False
