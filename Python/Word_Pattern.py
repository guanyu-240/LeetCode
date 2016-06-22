class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        words = str.split()
        if len(words) != len(pattern): return False
        m1 = {}
        m2 = {}
        for i in range(len(words)):
            word = m1.get(pattern[i])
            if word is None:
                if words[i] in m2.keys(): return False
                m1[pattern[i]] = words[i]
                m2[words[i]] = pattern[i]
            else:
                if word != words[i]: return False
        return True
