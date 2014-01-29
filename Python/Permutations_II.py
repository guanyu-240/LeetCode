class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, num):
        num.sort()
        return self.solve(num)
        
    def solve(self, num):
        ret = []
        for i in range(len(num)):
            if i > 0 and num[i] == num[i-1]: continue
            remain = num[0:i] + num[i+1:len(num)]
            subRet = self.solve(remain)
            if len(subRet) == 0:
                ret.append([num[i]])
                continue
            for p in subRet:
                ret.append([num[i]]+p)
        return ret
