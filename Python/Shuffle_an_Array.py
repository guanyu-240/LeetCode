class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type size: int
        """
        self.__initial = nums
        self.__current = list(self.__initial)

    def reset(self):
        """
        Resets the array to its original configuration and return it.
        :rtype: List[int]
        """
        self.__current = list(self.__initial)
        return self.__current

    def shuffle(self):
        """
        Returns a random shuffling of the array.
        :rtype: List[int]
        """
        n = len(self.__current)
        while n > 0:
            to_swap = random.randint(0, n-1)
            if to_swap < n-1:
                tmp = self.__current[n-1]
                self.__current[n-1] = self.__current[to_swap]
                self.__current[to_swap] = tmp
            n -= 1
        return self.__current


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
