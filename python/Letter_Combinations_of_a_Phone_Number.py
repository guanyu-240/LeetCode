class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        d = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        cands = [""]
        for digit in digits:
            if digit == None or ord(digit) < ord('2') or ord(digit) > ord('9'):
                continue
            tmp = []
            chars = d[ord(digit)-ord('2')]
            for cand in cands:
                for c in chars:
                    tmp.append(cand+c)
            cands = tmp
        return cands
