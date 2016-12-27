class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n <= 1: return n
        ret = 0
        increasing = 1
        prev_increasing = 0
        for i in range(1, n):
            if nums[i] > nums[i-1]: increasing += 1
            elif nums[i] < nums[i-1]:
                if increasing > 1: ret += 2
                elif prev_increasing == 0: ret += 1
                prev_increasing = increasing
                increasing = 1
        ret += min(2, increasing)
        return ret
