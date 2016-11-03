class RandomizedSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.numPos = {}
        self.nums = []

    def insert(self, val):
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        if val in self.numPos: return False
        else:
            self.nums.append(val)
            self.numPos[val] = len(self.nums)-1
            return True

    def remove(self, val):
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        :type val: int
        :rtype: bool
        """
        pos = self.numPos.get(val)
        if pos is None: return False
        del self.numPos[val]
        self.nums[pos] = self.nums[len(self.nums)-1]
        if pos != len(self.nums) - 1: self.numPos[self.nums[pos]] = pos
        self.nums.pop()
        return True

    def getRandom(self):
        """
        Get a random element from the set.
        :rtype: int
        """
        if len(self.nums) == 0: return None
        return self.nums[random.randint(0, len(self.nums)-1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
