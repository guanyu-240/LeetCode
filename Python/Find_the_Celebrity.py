# The knows API is already defined for you.
# @param a, person a
# @param b, person b
# @return a boolean, whether a knows b
# def knows(a, b):

class Solution(object):
    def findCelebrity(self, n):
        """
        :type n: int
        :rtype: int
        """
        celebrity = 0
        for i in range(1,n):
            # if the celebrity knows i, this celebrity is no longer valid
            # anybody in [celebrity, i] can not be candidate, since they all
            # knows some other people, then the only possible candidate is i
            if knows(celebrity, i):
                celebrity = i
        for i in range(n):
            if i != celebrity and (knows(celebrity, i) or not knows(i, celebrity)):
                return -1
        return celebrity
