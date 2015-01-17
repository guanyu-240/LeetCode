class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        return ''.join(sorted([str(n) for n in num], cmp=lambda x,y:cmp(y+x, x+y))).lstrip('0') or '0';
