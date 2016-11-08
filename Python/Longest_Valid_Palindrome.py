class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        count = {}
        for c in s:
            if c in count: count[c] += 1
            else: count[c] = 1
        ret = 0
        has_odd = False
        for k,v in count.iteritems():
            if v % 2 == 0: ret += v
            else: 
                ret += v-1
                has_odd = True
        ret += (1 if has_odd else 0)
        return ret
