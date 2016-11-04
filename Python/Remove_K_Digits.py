class Solution(object):
    def getNumber(self, num, start):
        while num[start] == '0' and start < len(num)-1:
            start += 1
        return ''.join(num[start:])
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        if k >= len(num): return '0'
        num = list(num)
        for i in range(k):
            j = i+1
            # then num[i] stores the candidate
            while j < len(num) and num[i] <= num[j]:
                # the candidate should not be removed, pushed next
                tmp = num[i]
                num[i] = num[j]
                num[j] = tmp
                j += 1
        return self.getNumber(num, k)
