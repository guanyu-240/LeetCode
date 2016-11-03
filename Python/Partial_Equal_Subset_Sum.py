class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        sum_all = sum(nums)
        if sum_all % 2 == 1: return False
        half = sum_all/2
        dp = [0 for i in range(half)]
        dp[0] = 1
        for x in nums:
            if x > half: return False
            elif x == half: return True
            for i in range(half-1, 0, -1):
                if dp[i] == 1:
                    if i+x == half: return True
                    elif i+x < half: dp[i+x] = 1
            dp[x] = 1
        return False
