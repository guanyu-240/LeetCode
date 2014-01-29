class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permute(self, num):
        ret = []
        for i in range(len(num)):
            remain = num[0:i] + num[i+1: len(num)]
            subRet = self.permute(remain)
            if (len(subRet) == 0): 
                ret.append([num[i]])
                continue
            for p in subRet:
                ret.append([num[i]]+p)
        return ret
