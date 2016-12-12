class PhoneDirectory(object):

    def __init__(self, maxNumbers):
        """
        Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory.
        :type maxNumbers: int
        """
        self.__used = set([])
        self.__released = collections.deque()
        self.__nextAvail = 0
        self.__maxNumbers = maxNumbers

    def get(self):
        """
        Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available.
        :rtype: int
        """
        ret = -1
        if len(self.__released) > 0: ret = self.__released.popleft()
        elif self.__nextAvail == -1: ret = -1
        else:
            ret = self.__nextAvail
            self.__nextAvail += 1
            if self.__nextAvail == self.__maxNumbers:
                self.__nextAvail = -1
        if ret != -1: self.__used.add(ret)
        return ret

    def check(self, number):
        """
        Check if a number is available or not.
        :type number: int
        :rtype: bool
        """
        return number not in self.__used

    def release(self, number):
        """
        Recycle or release a number.
        :type number: int
        :rtype: void
        """
        if number in self.__used:
            self.__used.remove(number)
            self.__released.append(number)


# Your PhoneDirectory object will be instantiated and called as such:
# obj = PhoneDirectory(maxNumbers)
# param_1 = obj.get()
# param_2 = obj.check(number)
# obj.release(number)
