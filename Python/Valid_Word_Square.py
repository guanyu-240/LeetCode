class Solution(object):
    def validWordSquare(self, words):
        """
        :type words: List[str]
        :rtype: bool
        """
        m = len(words) 
        if m == 0: return True
        n = len(words[0]) 
        if n == 0 or m != n: return False
        for d in range(n):
            if len(words[d]) > n: return False
            for i in range(d+1, len(words[d])):
                if len(words[i]) <= d: return False
                if words[d][i] != words[i][d]: return False
            for i in range(len(words[d]), n):
                if len(words[i]) > d: return False
        return True
