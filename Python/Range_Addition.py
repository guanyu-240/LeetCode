class Solution(object):
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        # store the sums to be used by its self and following elements
        incs = [0]*length
        for update in updates:
            x,y,val = update[0],update[1],update[2]
            incs[x] += val
            if y < length - 1:
                incs[y+1] -= val
        for i in range(1, length):
            incs[i] += incs[i-1]

        return incs
