class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        min_limit = -1 << 32
        max_num,second_max,third_max = min_limit,min_limit,min_limit
        for x in nums:
            if x > max_num:
                third_max = second_max
                second_max = max_num
                max_num = x
            elif second_max < x < max_num:
                third_max = second_max
                second_max = x
            elif third_max < x < second_max:
                third_max = x
        return third_max if third_max != min_limit else max_num
