class Solution(object):
    def findDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        ret = []
        for i in range(n):
            original = abs(nums[i])
            if nums[original-1] < 0: ret.append(original)
            nums[original-1] *= -1
        return ret
