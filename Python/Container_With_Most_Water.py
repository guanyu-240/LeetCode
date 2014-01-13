class Solution:
    # @return an integer
    """
    Reason for moving the pointer with smaller height
    current area: smaller*|index_larger - index_smaller|
    if moving the larger ptr, new area: min(smaller, newPtr)*(|index_larger - index_smaller| - 1) <= current
    if moving the smaller ptr, new area: min(newPtr, larger)*(|index_larger - index_smaller| - 1), UNKNOWN and needs to be compared
    """
    def maxArea(self, height):
        ret = 0
        n = len(height)
        left = 0
        right = -1
        while left - right < n:
            ret = max(ret, min(height[left], height[right])*(n+right-left))
            if height[left] < height[right]: left = left + 1
            else: right = right - 1
        return ret
