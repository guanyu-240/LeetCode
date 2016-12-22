class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        ret = []
        n = len(nums)
        for i in range(n):
            original = abs(nums[i])
            nums[original-1] = -abs(nums[original-1])
        for i in range(n):
            if nums[i] > 0: ret.append(i+1)
        return ret
