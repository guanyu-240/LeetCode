class Solution(object):
    def findLongestWord(self, s, d):
        """
        :type s: str
        :type d: List[str]
        :rtype: str
        """
        len_max = 0
        ret = ""
        for w in d:
            if self.isSubset(s, w):
                if len(w) > len_max:
                    ret = w
                    len_max = len(w)
                elif len(w) == len_max:
                    if w < ret:
                        ret = w
        return ret
                

    def isSubset(self, s1, s2):
        idx1, idx2 = 0, 0
        n1, n2 = len(s1), len(s2)
        while idx1 < n1 and idx2 < n2:
            if s1[idx1] == s2[idx2]:
                idx1 += 1
                idx2 += 1
                if idx2 == n2:
                    return True
            else:
                idx1 += 1
        return False
